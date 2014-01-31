#pragma once

#include <stdint.h>
#include "RenderContext.h"

namespace Slink
{
	enum class RenderContextType : unsigned int {
		DirectX11,
		OpenGL
	};

	void Init(int argc, char* argv[]);
	void InitWindow(uint32_t Width, uint32_t Height);
	RenderContext* InitContext(RenderContextType context);
	void Shutdown();

	typedef void (*RenderFunctionPtr)(void);
	void RenderFunction(RenderFunctionPtr);

	void MainLoop();
}

