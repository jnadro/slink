#include "slink\Slink.h"
#include <Awesomium/WebCore.h>

using namespace Awesomium;

Slink::RenderContext* ctx = nullptr;

auto Width = 1280, Height = 720;

void Render()
{
	ctx->SetRenderTarget();
	ctx->ClearScreen();
}

int main(int argc, char* argv[])
{
	Slink::Init(argc, argv);
	Slink::InitWindow(Width, Height);
	Slink::RenderFunction(Render);
	ctx = Slink::InitContext(Slink::RenderContextType::OpenGL);

	WebCore* web_core = WebCore::Initialize(WebConfig());
	
	Slink::MainLoop();

	WebCore::Shutdown();

	return 0;
}
