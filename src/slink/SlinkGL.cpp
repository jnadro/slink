#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "SlinkGL.h"
#include <assert.h>

namespace Slink
{
	namespace OpenGL
	{
		static HGLRC hRC = nullptr;                           // Permanent Rendering Context
		static HDC   hDC = nullptr;                           // Private GDI Device Context

		void OpenGLRenderContext::Init(HWND window, unsigned int WindowWidth, unsigned int WindowHeight)
		{
			hDC = GetDC(window);
			assert(hDC);
		}

		void OpenGLRenderContext::ClearScreen()
		{
		}

		void OpenGLRenderContext::SetRenderTarget()
		{
		}

		void OpenGLRenderContext::Present()
		{
		}
	}
}
