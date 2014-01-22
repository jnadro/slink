#ifndef SlinkDirectX11_h
#define SlinkDirectX11_h

#include "RenderContext.h"

namespace Slink
{
	namespace DirectX11
	{
		class DirectX11RenderContext : public RenderContext
		{
		public:
			virtual void Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight);
			virtual void Terminate();

			virtual void ClearScreen();
			virtual void SetRenderTarget();
			virtual void Present();
		};
	}
}

#endif
