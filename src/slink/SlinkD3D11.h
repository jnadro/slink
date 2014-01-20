#ifndef SlinkD3D11_h
#define SlinkD3D11_h

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

		void Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight);
	}
}

#endif
