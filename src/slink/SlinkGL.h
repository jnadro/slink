#ifndef SlinkGL_h
#define SlinkGL_h

#include "RenderContext.h"

namespace Slink
{
	class OpenGLRenderContext : public RenderContext
	{
	public:
		virtual void Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight);
		virtual void Terminate();

		virtual void ClearScreen();
		virtual void SetRenderTarget();
		virtual void Present();
		virtual void Draw() {}
	};
}

#endif
