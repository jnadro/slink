#include <Slink.h>
#include <RenderContext.h>
#include <mongoose.h>

Slink::RenderContext* ctx = nullptr;

auto Width = 1280, Height = 720;

void Render()
{
	ctx->SetRenderTarget();
	ctx->ClearScreen();
	ctx->Draw();
}

// This function will be called by mongoose on every new request
static int index_html(struct mg_connection *conn) {
  return 5;
}

int main(int argc, char* argv[])
{
	Slink::Init(argc, argv);
	Slink::InitWindow(Width, Height);
	Slink::RenderFunction(Render);
	ctx = Slink::InitContext(Slink::RenderContextType::DirectX11);

	struct mg_server *server;
	  server = mg_create_server(NULL);
	 mg_set_option(server, "listening_port", "8080");
	mg_set_request_handler(server, index_html);
	
	Slink::MainLoop();

	Slink::Shutdown();

	return 0;
}
