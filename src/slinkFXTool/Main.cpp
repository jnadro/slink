#include <Slink.h>
#include <RenderContext.h>
#include <mongoose.h>
#include <stdio.h>

Slink::RenderContext* ctx = nullptr;
struct mg_server *server = nullptr;
uint32_t current_timer = 0, last_timer = 0;

auto Width = 1280, Height = 720;

void Render()
{
	//obviously this code sucks.
	mg_poll_server(server, 1000);

	ctx->SetRenderTarget();
	ctx->ClearScreen();
	ctx->Draw();

	Slink::SwapBuffers();
}

// This function will be called by mongoose on every new request
static int index_html(struct mg_connection *conn) {

  if (conn->is_websocket) {
    // This handler is called for each incoming websocket frame, one or more
    // times for connection lifetime.
    // Echo websocket data back to the client.
    mg_websocket_write(conn, 1, conn->content, conn->content_len);
    return MG_CLIENT_CONTINUE;
  }

  return MG_REQUEST_PROCESSED;
}

int main(int argc, char* argv[])
{
	Slink::Init(argc, argv);
	Slink::InitWindow(Width, Height);
	ctx = Slink::InitContext(Slink::RenderContextType::DirectX11);

	server = mg_create_server(nullptr);
	mg_set_option(server, "listening_port", "8080");
	mg_set_request_handler(server, index_html);
	
	while (!Slink::WindowShouldClose()) {

		Render();

		Slink::PollEvents();
	}

	Slink::Shutdown();

	// Cleanup, and free server instance
	mg_destroy_server(&server);

	return 0;
}
