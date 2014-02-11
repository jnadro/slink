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

enum class Commands : unsigned int {
	CreateTriangle
};

// This function will be called by mongoose on every new request
static int receive(struct mg_connection* conn) {

  if (conn->is_websocket) {

	long int command = strtol(conn->content, nullptr, 10);

	switch (command)
	{
		case Commands::CreateTriangle:
		{
			const char* msg = "Create Triangle";
			mg_websocket_write(conn, 1, msg, strlen(msg));
			break;
		}
		default:
		{
			const char* errorMessage = "Unknown command.";
			mg_websocket_write(conn, 1, errorMessage, strlen(errorMessage));
		}
	}

    return MG_CLIENT_CONTINUE;
  }

  return MG_REQUEST_PROCESSED;
}

int main(int argc, char* argv[])
{
	Slink::Init(argc, argv);
	Slink::InitWindow(Width, Height);
	ctx = Slink::InitContext(Slink::RenderContextType::DirectX11);

	AllocConsole();
	FILE* output;
	freopen_s(&output, "CONOUT$", "wb", stdout);

	server = mg_create_server(nullptr);
	mg_set_option(server, "listening_port", "8080");
	mg_set_request_handler(server, receive);

	puts("listening on port 8080...");
	
	while (!Slink::WindowShouldClose()) {
		Slink::PollEvents();

		Render();
	}

	fclose(stdout);
	FreeConsole();

	Slink::Shutdown();

	// Cleanup, and free server instance
	mg_destroy_server(&server);

	return 0;
}
