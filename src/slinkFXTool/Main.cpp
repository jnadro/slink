#include <Slink.h>
#include <RenderContext.h>

Slink::RenderContext* ctx = nullptr;

auto Width = 1280, Height = 720;

void Render()
{
	ctx->SetRenderTarget();
	ctx->ClearScreen();
	ctx->Draw();
}

int main(int argc, char* argv[])
{
	Slink::Init(argc, argv);
	Slink::InitWindow(Width, Height);
	Slink::RenderFunction(Render);
	ctx = Slink::InitContext(Slink::RenderContextType::DirectX11);
	
	Slink::MainLoop();

	return 0;
}
