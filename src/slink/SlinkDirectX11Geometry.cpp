#include <d3d11.h>
#include "SlinkDirectX11Geometry.h"
#include "SlinkHelpers.h"

namespace Slink
{
	extern ID3D11DeviceContextPtr Context;

	// Define the input layout
	static D3D11_INPUT_ELEMENT_DESC SimpleVertexDecl[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
	};
	static UINT SimpleVertexNumElements = ARRAYSIZE(SimpleVertexDecl);
	static UINT SimpleVertexStride = 3 * sizeof(float); // in bytes

	Geometry::Geometry()
		: indexBuffer(nullptr),
		  vertexBuffer(nullptr),
		  vsBlob(nullptr),
		  created(false),
		  numVertices(0)
	{
	}

	Geometry::~Geometry() 
	{
	}

	static ID3D11BufferPtr createBuffer(ID3D11DevicePtr device, const float* const verts, int numVerts) {
		assert(device);
		assert(verts);
		assert(numVerts > 0);

		D3D11_BUFFER_DESC bufferDesc = {0};
		bufferDesc.ByteWidth = numVerts * 3 * sizeof(float);
		bufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initData = {0};
		initData.pSysMem = verts;

		ID3D11BufferPtr vertexBuffer = nullptr;
		VERIFYDX(device->CreateBuffer(&bufferDesc, &initData, &vertexBuffer));

		return vertexBuffer;
	}

	void Geometry::createFromData(ID3D11DevicePtr device, const float* const verts, int numVerts) {
		assert(!created);
		assert(vsBlob);

		numVertices = numVerts;

		vertexBuffer = createBuffer(device, verts, numVertices);

		device->CreateInputLayout(SimpleVertexDecl, SimpleVertexNumElements, vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), &inputLayout);
		
		created = true;
	}

	void Geometry::setVertexShader(ID3DBlobPtr shader) {
		assert(vsBlob == nullptr);
		vsBlob = shader;
	}

	void Geometry::draw() {
		if (!created)
			return;

		// Set Input Assembly State.
		Context->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		Context->IASetInputLayout(inputLayout);
		UINT Strides[1] = { SimpleVertexStride };
		UINT Offsets[1] = { 0 };
		Context->IASetVertexBuffers(0, 1, &vertexBuffer, Strides, Offsets);

		Context->Draw(numVertices, 0);
	}
}