#ifndef WINDOW_H
#define WINDOW_H

#include <d3d11.h>
#include "ResourcePointers.h"
#include "RenderContext.h"

namespace Slink
{
	using namespace DX11Ptr;

	enum class RenderContextType : unsigned int {
		DirectX11,
		OpenGL
	};

	void Init(int argc, char* argv[]);
	void InitWindow(UINT Width, UINT Height);
	RenderContext* InitContext(RenderContextType context);

	typedef void (*RenderFunctionPtr)(void);
	void RenderFunction(RenderFunctionPtr);

	void MainLoop();

	ID3D11VertexShaderPtr LoadVSBinary(ID3D11DevicePtr Device, const char* Filename);
	ID3D11PixelShaderPtr LoadPSBinary(ID3D11DevicePtr Device, const char* Filename);

	ID3D11BufferPtr CreateVertexBuffer(ID3D11DevicePtr Device, void* Data, UINT BufferSize);

	class Geometry* QuadGeometry();
}

#endif
