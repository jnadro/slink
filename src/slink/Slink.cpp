#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <windows.h>
#include <assert.h>
#include "Slink.h"
#include "SlinkHelpers.h"
#include "SlinkD3D11.h"
#include "SlinkGL.h"
#include "RenderContext.h"

namespace Slink
{
	static HWND window = nullptr;
	static RenderFunctionPtr ClientRenderFunction = nullptr;
	static UINT WindowWidth = 0, WindowHeight = 0;

	static RenderContext* ctx = nullptr;

	using namespace DX11Ptr;

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
		ClientRenderFunction = nullptr;
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
			ctx = new DirectX11::DirectX11RenderContext();
			ctx->Init(window, WindowWidth, WindowHeight);
		}
		else if (context == RenderContextType::OpenGL) {
			ctx = new OpenGL::OpenGLRenderContext();
			ctx->Init(window, WindowWidth, WindowHeight);
		}

		return ctx;
	}

	void RenderFunction(RenderFunctionPtr r) {
		ClientRenderFunction = r;
	}

	void MainLoop() {
		// Ensure the user has specified a render function.
		assert(ClientRenderFunction);

		MSG msg = {0};
		while (GetMessage(&msg, nullptr, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			ClientRenderFunction();

			ctx->Present();
		}

		ctx->Terminate();
	}
}