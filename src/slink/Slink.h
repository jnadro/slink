#ifndef WINDOW_H
#define WINDOW_H

#include <d3d11.h>
#include "ResourcePointers.h"

namespace Slink
{
	using namespace DX11Ptr;

	enum class RenderContext : unsigned int {
		DirectX11,
		OpenGL
	};

	void Init(int argc, char* argv[]);
	void InitWindow(UINT Width, UINT Height);
	void InitContext(RenderContext context);

	namespace DirectX11
	{
		ID3D11DeviceContextPtr GetContext();
		ID3D11DevicePtr GetDevice();
		ID3D11RenderTargetViewPtr GetBackBufferView();
	}

	typedef void (*RenderFunctionPtr)(void);
	void RenderFunction(RenderFunctionPtr);

	void MainLoop();

	ID3D11VertexShaderPtr LoadVSBinary(ID3D11DevicePtr Device, const char* Filename);
	ID3D11PixelShaderPtr LoadPSBinary(ID3D11DevicePtr Device, const char* Filename);

	ID3D11BufferPtr CreateVertexBuffer(ID3D11DevicePtr Device, void* Data, UINT BufferSize);

	class Geometry* QuadGeometry();
}

#endif
