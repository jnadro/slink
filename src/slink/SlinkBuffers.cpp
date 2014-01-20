#include "Slink.h"
#include "SlinkHelpers.h"

namespace Slink
{
	// Define the input layout
	static D3D11_INPUT_ELEMENT_DESC SimpleVertexDecl[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
		//{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
		//{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};
	static UINT SimpleVertexNumElements = ARRAYSIZE(SimpleVertexDecl);

	ID3D11BufferPtr CreateVertexBuffer(ID3D11DevicePtr Device, void* Data, UINT BufferSize) {
		assert(Device);
		assert(Data);
		assert(BufferSize > 0);

		D3D11_BUFFER_DESC bufferDesc = {0};
		bufferDesc.ByteWidth = BufferSize;
		bufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initData = {0};
		initData.pSysMem = Data;

		ID3D11BufferPtr vertexBuffer = nullptr;
		VERIFYDX(Device->CreateBuffer(&bufferDesc, &initData, &vertexBuffer));

		assert(vertexBuffer.GetInterfacePtr());
		return vertexBuffer;
	}
}
