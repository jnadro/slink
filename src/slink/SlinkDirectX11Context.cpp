#include <d3d11.h>
#include "SlinkDirectX11Context.h"
#include "SlinkDirectX11Shaders.h"
#include "SlinkDirectX11Geometry.h"
#include "ShaderStrings.cpp"
#include "ResourcePointers.h"
#include "SlinkHelpers.h"

namespace Slink
{
	ID3D11DeviceContextPtr		Context			= nullptr;

	static Shader						simple;
	static Geometry						triangle;

	DirectX11RenderContext::DirectX11RenderContext()
		:	context(nullptr),
			backBuffer(nullptr),
			backBufferView(nullptr),
			swapChain(nullptr),
			device(nullptr)
	{
	}

	DirectX11RenderContext::~DirectX11RenderContext()
	{
	}

	void DirectX11RenderContext::Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight)
	{
		const UINT NumFeatureLevels = 3;

		D3D_FEATURE_LEVEL FeatureLevels[NumFeatureLevels] = {	D3D_FEATURE_LEVEL_11_0,
																D3D_FEATURE_LEVEL_10_1,
																D3D_FEATURE_LEVEL_10_0,
															};

		DXGI_SWAP_CHAIN_DESC sd = {0};
		sd.BufferCount = 1;
		sd.BufferDesc.Width = WindowWidth;
		sd.BufferDesc.Height = WindowHeight;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = window;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		//Create swap chain, device, and immediate context.
		UINT Flags = 0;
#if _DEBUG
		Flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
		VERIFYDX(D3D11CreateDeviceAndSwapChain(	nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, Flags, FeatureLevels, NumFeatureLevels,
												D3D11_SDK_VERSION, &sd, &swapChain, &device, nullptr, &Context));

		// Create a render target view
		VERIFYDX(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer)); 
		VERIFYDX(device->CreateRenderTargetView(backBuffer, nullptr, &backBufferView));

		//Test Code!
		simple.createFromString(std::string(VS), std::string(PS), device);

		float verts[9] = {-1.0f, -1.0f, 0.0f,
						   0.0f,  1.0f, 0.0f,
						   1.0f, -1.0f, 0.0f};
		triangle.setVertexShader(simple.getBytecode());
		triangle.createFromData(device, verts, 3); 
	}

	void DirectX11RenderContext::Terminate()
	{
	}

	void DirectX11RenderContext::ClearScreen()
	{
		float ClearColor[4] = { 1.0f, 0.5f, 0.5f, 1.0f };
		Context->ClearRenderTargetView(backBufferView, ClearColor);
	}

	void DirectX11RenderContext::SetRenderTarget()
	{
		Context->OMSetRenderTargets(1, &backBufferView.GetInterfacePtr(), nullptr);

		D3D11_TEXTURE2D_DESC desc;
		backBuffer->GetDesc(&desc);

		// Setup the viewport
		D3D11_VIEWPORT vp = { 0.0f, 0.0f, (FLOAT)desc.Width, (FLOAT)desc.Height, 0.0f, 1.0f };
		Context->RSSetViewports(1, &vp);
	}

	void DirectX11RenderContext::Draw() {
		simple.set();
		triangle.draw();
	}

	void DirectX11RenderContext::Present() {
		swapChain->Present(0, 0);
	}
}
