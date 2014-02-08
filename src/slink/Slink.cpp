#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <windows.h>
#include <assert.h>
#include "Slink.h"
#include "SlinkHelpers.h"
#include "SlinkDirectX11Context.h"
#include "SlinkGL.h"
#include "RenderContext.h"
#include "Scene.h"
#include "SlinkObject.h"

namespace Slink
{
	static HWND window = nullptr;
	static UINT WindowWidth = 0, WindowHeight = 0;
	static MSG msg = {0};


	static RenderContext* ctx = nullptr;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		switch(message)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}

	void Init(int argc, char* argv[]) {
		window = nullptr;
	}

	void InitWindow(UINT Width, UINT Height) {
		assert(Width > 0 && Height > 0);

		const LPCWSTR windowName = L"Slink";
		const HINSTANCE hInstance = GetModuleHandle(nullptr);

		WindowWidth = Width;
		WindowHeight = Height;

		WNDCLASS wc      = {0}; 
		wc.lpfnWndProc   = WndProc;
		wc.hInstance     = hInstance;
		wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
		wc.lpszClassName = windowName;

		RegisterClass(&wc);

		window = CreateWindow(	wc.lpszClassName,
								windowName,
								WS_OVERLAPPEDWINDOW | WS_VISIBLE,
								0, 0, WindowWidth, WindowHeight, 0, 0, hInstance, nullptr);
	}

	RenderContext* InitContext(RenderContextType context) {

		if (context == RenderContextType::DirectX11) {
			ctx = new DirectX11RenderContext();
			ctx->Init(window, WindowWidth, WindowHeight);
		}
		else if (context == RenderContextType::OpenGL) {
			ctx = new OpenGLRenderContext();
			ctx->Init(window, WindowWidth, WindowHeight);
		}

		return ctx;
	}

	void Shutdown()
	{
		ctx->Terminate();

		delete ctx;
		ctx = nullptr;
	}

	void SwapBuffers() {
		ctx->Present();
	}

	void PollEvents() {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
	}

	bool WindowShouldClose() {
		return WM_QUIT == msg.message;
	}
}