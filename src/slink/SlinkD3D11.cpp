#include <d3d11.h>
#include "SlinkD3D11.h"
#include "ResourcePointers.h"
#include "SlinkHelpers.h"

namespace Slink
{
	namespace DirectX11
	{
		using namespace DX11Ptr;

		static IDXGISwapChainPtr			SwapChain		= nullptr;
		static ID3D11DevicePtr				Device			= nullptr;
		static ID3D11DeviceContextPtr		Context			= nullptr;
		static ID3D11RenderTargetViewPtr	BackBufferView	= nullptr;

		void Init(HWND window, UINT WindowWidth, UINT WindowHeight)
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
													D3D11_SDK_VERSION, &sd, &SwapChain, &Device, nullptr, &Context));

			// Create a render target view
			ID3D11Texture2DPtr pBackBuffer;
			VERIFYDX(SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer));
	 
			VERIFYDX(Device->CreateRenderTargetView(pBackBuffer, nullptr, &BackBufferView));
		}


		ID3D11DeviceContextPtr GetContext() {
			assert(Context.GetInterfacePtr());
			return Context;
		}

		ID3D11DevicePtr GetDevice() {
			assert(Device.GetInterfacePtr());
			return Device;
		}

		ID3D11RenderTargetViewPtr GetBackBufferView() {
			assert(BackBufferView.GetInterfacePtr());
			return BackBufferView;
		}

		void Present() {
			SwapChain->Present(0, 0);
		}
	}
}
