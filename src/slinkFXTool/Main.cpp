#include <Slink.h>
#include <RenderContext.h>
#include <mongoose.h>

Slink::RenderContext* ctx = nullptr;
struct mg_server *server = nullptr;

auto Width = 1280, Height = 720;

void Render()
{
	mg_poll_server(server, 1000);

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

	server = mg_create_server(nullptr);
	mg_set_option(server, "listening_port", "8080");
	mg_set_request_handler(server, index_html);
	
	Slink::MainLoop();

	Slink::Shutdown();

	// Cleanup, and free server instance
	mg_destroy_server(&server);

	return 0;
}
