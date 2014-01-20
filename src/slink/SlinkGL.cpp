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

			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd  
				1,								// version number  
				PFD_DRAW_TO_WINDOW |			// support window  
				PFD_SUPPORT_OPENGL |			// support OpenGL  
				PFD_DOUBLEBUFFER,				// double buffered  
				PFD_TYPE_RGBA,					// RGBA type  
				24,								// 24-bit color depth  
				0, 0, 0, 0, 0, 0,				// color bits ignored  
				0,								// no alpha buffer  
				0,								// shift bit ignored  
				0,								// no accumulation buffer  
				0, 0, 0, 0,						// accum bits ignored  
				32,								// 32-bit z-buffer      
				0,								// no stencil buffer  
				0,								// no auxiliary buffer  
				PFD_MAIN_PLANE,					// main layer  
				0,								// reserved  
				0, 0, 0							// layer masks ignored  
			}; 

			int  iPixelFormat = ChoosePixelFormat(hDC, &pfd);
			SetPixelFormat(hDC, iPixelFormat, &pfd);

			hRC = wglCreateContext(hDC);

			wglMakeCurrent(hDC, hRC);
		}

		void OpenGLRenderContext::Terminate()
		{
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(hRC);
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
