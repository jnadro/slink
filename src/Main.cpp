#include "slink\Slink.h"
#include <DirectXMath.h>
#include <Awesomium/WebCore.h>

using namespace Slink::DX11Ptr;
using namespace DirectX;
using namespace Awesomium;

ID3D11DeviceContextPtr Context = nullptr;
ID3D11DevicePtr Device = nullptr;
ID3D11RenderTargetViewPtr BackBufferView = nullptr;
ID3D11VertexShaderPtr vertexShader = nullptr;
ID3D11PixelShaderPtr pixelShader = nullptr;
ID3D11BufferPtr triangle = nullptr;

auto Width = 1280, Height = 720;

struct SimpleVertex
{
    XMFLOAT3 Position;
	XMFLOAT4 Color;
	XMFLOAT3 Normal;
};

void Render()
{
	Context->OMSetRenderTargets(1, &BackBufferView.GetInterfacePtr(), nullptr);

	// Setup the viewport
	D3D11_VIEWPORT vp = { (FLOAT)Width, (FLOAT)Height, 0.0f, 1.0f, 0, 0 };
	Context->RSSetViewports(1, &vp);

	float ClearColor[4] = { 1.0f, 0.5f, 0.5f, 1.0f };
	Context->ClearRenderTargetView(BackBufferView, ClearColor);
}

void init()
{
	/*
	vertexShader = Slink::LoadVSBinary(Device, "MeshVS");
	pixelShader = Slink::LoadPSBinary(Device, "MeshPS");

	SimpleVertex vertices[] =
    {
		{XMFLOAT3(0.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 0.5f, 0.5f, 1.0f), XMFLOAT3(0.0f, 0.5f, 0.5f)},
		{XMFLOAT3(0.5f, -0.5f, 0.5f), XMFLOAT4(0.0f, 0.5f, 0.5f, 1.0f), XMFLOAT3(0.0f, 0.5f, 0.5f)},
		{XMFLOAT3(-0.5f, -0.5f, 0.5f), XMFLOAT4(0.0f, 0.5f, 0.5f, 1.0f), XMFLOAT3(0.0f, 0.5f, 0.5f)},
    };
	triangle = Slink::CreateVertexBuffer(Device, vertices, 3 * sizeof(SimpleVertex));
	*/
}

int main(int argc, char* argv[])
{
	Slink::Init(argc, argv);
	Slink::InitWindow(Width, Height);
	Slink::RenderFunction(Render);
	Slink::InitContext(Slink::RenderContext::DirectX11);

	Device = Slink::DirectX11::GetDevice();
	Context = Slink::DirectX11::GetContext();
	BackBufferView = Slink::DirectX11::GetBackBufferView();

	init();

	WebCore* web_core = WebCore::Initialize(WebConfig());
	
	Slink::MainLoop();

	WebCore::Shutdown();

	return 0;
}
