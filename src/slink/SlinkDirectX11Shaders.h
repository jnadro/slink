#pragma once

#include "ResourcePointers.h"
#include <string>

namespace Slink
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		bool createFromString(std::string vertex, std::string pixel, ID3D11DevicePtr device);

		ID3DBlobPtr getBytecode() const;

		void set() const;

	private:
		ID3D11VertexShaderPtr vertexShader;
		ID3D11PixelShaderPtr pixelShader;

		ID3DBlobPtr vsBlob;
	};
}

