#include "Slink.h"
#include "SlinkGeometry.h"

namespace Slink
{
	// Define the input layout
	static D3D11_INPUT_ELEMENT_DESC SimpleVertexDecl[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }, 
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};
	static UINT SimpleVertexNumElements = ARRAYSIZE(SimpleVertexDecl);

	static Geometry Quad;

	Geometry::Geometry()
	{
	}
	Geometry::~Geometry()
	{
	}

	Geometry* QuadGeometry()
	{
		return &Quad;
	}
}