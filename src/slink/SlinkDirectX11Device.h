#pragma once

#include "RenderDevice.h"

namespace Slink
{
	class DirectX11RenderDevice : public RenderDevice
	{
	public:
		virtual void createTriangleGeometry() override;
	};
}
