#include <d3d11.h>
#include <d3dcompiler.h>
#include "SlinkDirectX11Shaders.h"
#include "SlinkHelpers.h"

namespace Slink
{
	Shader::Shader()
		: vertexShader(nullptr),
		  pixelShader(nullptr)
	{
	}

	Shader::~Shader() {
	}

	static ID3DBlob* CompileShader(const char* shaderCode, size_t shaderLength, const char* shaderProfile) {
		ID3DBlob* blob = nullptr;
		ID3DBlob* errors = nullptr;
		HRESULT hr = D3DCompile(shaderCode, shaderLength, nullptr, nullptr, nullptr, "Main", shaderProfile, 0, 0, &blob, &errors);

		if (FAILED(hr)) {

			if (errors) {
				OutputDebugStringA((char*)errors->GetBufferPointer());
				errors->Release();
			}

			SAFE_RELEASE(blob);

			return nullptr;
		}

		return blob;
	}

	bool Shader::createFromString(std::string vertex, std::string pixel, ID3D11DevicePtr device) {
		auto vsBlob = CompileShader(vertex.c_str(), vertex.length(), "vs_5_0");
		if (vsBlob == nullptr) 
			return false;

		auto psBlob = CompileShader(pixel.c_str(), pixel.length(), "ps_5_0");
		if (psBlob == nullptr) {
			SAFE_RELEASE(vsBlob);
			return false;
		}

		VERIFYDX(device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader));
		VERIFYDX(device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader));

		SAFE_RELEASE(vsBlob);
		SAFE_RELEASE(psBlob);

		return true;
	}
}
