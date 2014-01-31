#pragma once

#include "RenderContext.h"

namespace Slink
{
	class OpenGLRenderContext : public RenderContext
	{
	public:
		virtual void Init(HWND window, uint32_t WindowWidth, uint32_t WindowHeight) override;
		virtual void Terminate() override;

		virtual void ClearScreen() override;
		virtual void SetRenderTarget() override;
		virtual void Present() override;
		virtual void Draw()  override {}
	};
}

