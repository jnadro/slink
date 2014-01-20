#include "Slink.h"
#include "SlinkHelpers.h"
#include <fstream>
#include <string>

namespace Slink
{
	using namespace DX11Ptr;
	using namespace std;

	static const string ShaderDir("shaders\\");
	static const string ShaderBinaryExtension(".cso");

	static void* LoadFile(string Filename, UINT& Filesize) {
		char* blob = nullptr;
		Filesize = 0;

		ifstream file(Filename, ios::in | ios::binary | ios::ate);

		if (file.is_open()) {
			auto size = file.tellg();
			assert(size > 0);

			Filesize = (UINT)size;

			file.seekg(0, ios::beg);

			blob = new char[Filesize];
			assert(blob);

			file.read(blob, size);
			file.close();
		}

		assert(blob);
		return blob;
	}

	ID3D11VertexShaderPtr LoadVSBinary(ID3D11DevicePtr Device, const char* Filename) {
		assert(Filename);
		assert(Device);

		UINT BytecodeSize = 0;
		const auto blob = LoadFile(ShaderDir + string(Filename) + ShaderBinaryExtension, BytecodeSize);
		assert(blob);

		ID3D11VertexShaderPtr VS;
		VERIFYDX(Device->CreateVertexShader(blob, BytecodeSize, nullptr, &VS));
		assert(VS.GetInterfacePtr());
		
		delete blob;

		return VS;
	}

	ID3D11PixelShaderPtr LoadPSBinary(ID3D11DevicePtr Device, const char* Filename) {
		assert(Filename);
		assert(Device);

		UINT BytecodeSize = 0;
		const auto blob = LoadFile(ShaderDir + string(Filename) + ShaderBinaryExtension, BytecodeSize);
		assert(blob);

		ID3D11PixelShaderPtr PS;
		VERIFYDX(Device->CreatePixelShader(blob, BytecodeSize, nullptr, &PS));
		assert(PS.GetInterfacePtr());
		
		delete blob;

		return PS;
	}
}
