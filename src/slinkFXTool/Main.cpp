#include <Slink.h>
#include <RenderContext.h>
#include <mongoose.h>
#include <stdio.h>

Slink::RenderContext* ctx = nullptr;
struct mg_server *server = nullptr;
uint32_t current_timer = 0, last_timer = 0;

auto Width = 1280, Height = 720;

static int iterate_callback(struct mg_connection *c) {
  if (c->is_websocket) {
    char buf[20];
    int len = _snprintf(buf, sizeof(buf), "%d", * (int *) c->connection_param);
    mg_websocket_write(c, 1, buf, len);
  }
  return MG_REQUEST_PROCESSED;
}

void Render()
{
	//obviously this code sucks.
	current_timer = mg_poll_server(server, 1000);

	if (current_timer - last_timer > 0) {
		last_timer = current_timer;
		mg_iterate_over_connections(server, iterate_callback, &current_timer);
	}

	ctx->SetRenderTarget();
	ctx->ClearScreen();
	ctx->Draw();
}

// This function will be called by mongoose on every new request
static int index_html(struct mg_connection *conn) {

  if (conn->is_websocket) {
    // This handler is called for each incoming websocket frame, one or more
    // times for connection lifetime.
    // Echo websocket data back to the client.
    mg_websocket_write(conn, 1, conn->content, conn->content_len);
    return conn->content_len == 4 && !memcmp(conn->content, "exit", 4) ?
      MG_CLIENT_CLOSE : MG_CLIENT_CONTINUE;
  } else {
    mg_send_header(conn, "Content-Type", "text/html");
    mg_send_data(conn, "hello world", strlen("hello world"));
    return MG_REQUEST_PROCESSED;
  }
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
