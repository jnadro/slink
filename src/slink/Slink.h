#pragma once

#include "RenderContext.h"

namespace Slink
{
	enum class RenderContextType : unsigned int {
		DirectX11,
		OpenGL
	};

	void Init(int argc, char* argv[]);
	void InitWindow(UINT Width, UINT Height);
	RenderContext* InitContext(RenderContextType context);

	typedef void (*RenderFunctionPtr)(void);
	void RenderFunction(RenderFunctionPtr);

	void MainLoop();
}

