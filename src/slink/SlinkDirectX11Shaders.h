#ifndef SlinkDirectX11Shaders_h
#define SlinkDirectX11Shaders_h

#include "ResourcePointers.h"
#include <string>

namespace Slink
{
	namespace DirectX11
	{
		class Shader
		{
		public:
			Shader();
			~Shader();

			bool createFromString(std::string vertex, std::string pixel, ID3D11DevicePtr device);

		private:
			ID3D11VertexShaderPtr vertexShader;
			ID3D11PixelShaderPtr pixelShader;
		};
	}
}

#endif
