#include <d3d11.h>
#include <d3dcompiler.h>
#include "SlinkDirectX11Shaders.h"

namespace Slink
{
	namespace DirectX11
	{
		Shader::Shader()
		{
		}

		Shader::~Shader()
		{
		}

		static ID3DBlob* CompileShader(const char* shaderCode, size_t shaderLength, const char* shaderProfile)
		{
			ID3DBlob* blob = nullptr;
			ID3DBlob* errors = nullptr;
			HRESULT hr = D3DCompile(shaderCode,
									shaderLength,
									nullptr,
									nullptr,
									nullptr,
									"Main",
									shaderProfile,
									0,
									0,
									&blob,
									&errors);

			if (FAILED(hr))
			{
				if (errors) {
					OutputDebugStringA((char*)errors->GetBufferPointer());
					errors->Release();
				}

				if (blob)
				   blob->Release();

				return nullptr;
			}

			return blob;
		}

		bool Shader::createFromString(std::string vertex, std::string pixel)
		{
			ID3DBlob* vsBlob = CompileShader(vertex.c_str(), vertex.length(), "vs_5_0");
			ID3DBlob* psBlob = CompileShader(pixel.c_str(), pixel.length(), "ps_5_0");

			if (vsBlob == nullptr || psBlob == nullptr) {
				vsBlob->Release();
				psBlob->Release();

				return false;
			}


			// Do Stuff!

			return true;
		}
	}
}
