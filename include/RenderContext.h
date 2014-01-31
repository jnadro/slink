#pragma once

#include <windows.h>
#include <stdint.h>

namespace Slink
{
	class RenderContext
	{
	public:
		virtual void Init(HWND window, uint32_t WindowWidth, uint32_t WindowHeight) = 0;
		virtual void Terminate() = 0;

		virtual void ClearScreen() = 0;
		virtual void SetRenderTarget() = 0;
		virtual void Present() = 0;
		virtual void Draw() = 0;
	};
}

