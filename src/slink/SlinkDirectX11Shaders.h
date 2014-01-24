#ifndef SlinkDirectX11Shaders_h
#define SlinkDirectX11Shaders_h

#include "ResourcePointers.h"
#include <string>

namespace Slink
{
	namespace DirectX11
	{
		using namespace DX11Ptr;

		class Shader
		{
		public:
			Shader();
			~Shader();

			bool createFromString(std::string vertex, std::string pixel);

		private:
			ID3D11VertexShaderPtr VertexShader;
			ID3D11PixelShaderPtr PixelShader;
		};
	}
}

#endif
