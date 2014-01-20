#include "slink\Slink.h"
#include <DirectXMath.h>
#include <Awesomium/WebCore.h>

using namespace Slink::DX11Ptr;
using namespace DirectX;
using namespace Awesomium;

ID3D11DeviceContextPtr Context = nullptr;
ID3D11DevicePtr Device = nullptr;
ID3D11RenderTargetViewPtr BackBufferView = nullptr;

auto Width = 1280, Height = 720;

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
