#ifndef SlinkDirectX11_h
#define SlinkDirectX11_h

#include "RenderContext.h"

namespace Slink
{
	class DirectX11RenderContext : public RenderContext
	{
	public:
		virtual void Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight) override;
		virtual void Terminate() override;

		virtual void ClearScreen() override;
		virtual void SetRenderTarget() override;
		virtual void Present() override;
		virtual void Draw() override;
	};
}

#endif
