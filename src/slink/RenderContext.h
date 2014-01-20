#ifndef RenderContext_h
#define RenderContext_h

namespace Slink
{
	class RenderContext
	{
	public:
		virtual void Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight) = 0;
		virtual void ClearScreen() = 0;
		virtual void SetRenderTarget() = 0;
	};
}

#endif
