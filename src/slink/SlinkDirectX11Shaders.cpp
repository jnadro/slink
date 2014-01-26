#include <d3d11.h>
#include <d3dcompiler.h>
#include "SlinkDirectX11Shaders.h"
#include "SlinkHelpers.h"

namespace Slink
{
	extern ID3D11DeviceContextPtr Context;

	Shader::Shader()
		: vertexShader(nullptr),
		  pixelShader(nullptr),
		  vsBlob(nullptr)
	{
	}

	Shader::~Shader() {
	}

	static ID3DBlobPtr CompileShader(const char* shaderCode, size_t shaderLength, const char* shaderProfile) {
		ID3DBlobPtr blob = nullptr;
		ID3DBlobPtr errors = nullptr;
		HRESULT hr = D3DCompile(shaderCode, shaderLength, nullptr, nullptr, nullptr, "Main", shaderProfile, 0, 0, &blob, &errors);

		if (FAILED(hr)) {

			if (errors) {
				OutputDebugStringA((char*)errors->GetBufferPointer());
				errors->Release();
			}

			return nullptr;
		}

		return blob;
	}

	bool Shader::createFromString(std::string vertex, std::string pixel, ID3D11DevicePtr device) {
		vsBlob = CompileShader(vertex.c_str(), vertex.length(), "vs_5_0");
		if (vsBlob == nullptr) 
			return false;

		auto psBlob = CompileShader(pixel.c_str(), pixel.length(), "ps_5_0");
		if (psBlob == nullptr) {
			return false;
		}

		VERIFYDX(device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), nullptr, &vertexShader));
		VERIFYDX(device->CreatePixelShader(psBlob->GetBufferPointer(), psBlob->GetBufferSize(), nullptr, &pixelShader));

		return true;
	}

	ID3DBlobPtr Shader::getBytecode() const {
		return vsBlob;
	}

	void Shader::set() const {
		Context->VSSetShader(vertexShader, nullptr, 0);
		Context->PSSetShader(pixelShader, nullptr, 0);
	}
}
