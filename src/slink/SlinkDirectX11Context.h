#pragma once

#include "RenderContext.h"
#include "ResourcePointers.h"

namespace Slink
{
	class DirectX11RenderContext : public RenderContext
	{
	public:
		DirectX11RenderContext();
		virtual ~DirectX11RenderContext();
		virtual void Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight) override;
		virtual void Terminate() override;

		virtual void ClearScreen() override;
		virtual void SetRenderTarget() override;
		virtual void Present() override;
		virtual void Draw() override;

	private:
		ID3D11DeviceContextPtr context;
		ID3D11Texture2DPtr backBuffer;
		ID3D11RenderTargetViewPtr backBufferView;
		IDXGISwapChainPtr swapChain;
		ID3D11DevicePtr device;
	};
}
