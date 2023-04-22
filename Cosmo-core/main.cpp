#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/graphics/shader.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/index_buffer.h"
#include "src/graphics/buffers/vertex_array.h"

#include "src/graphics/renderer2D.h"
#include "src/graphics/simple2Drenderer.h"
#include "src/graphics/batchrenderer2D.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"

#include <vector>
#include <time.h>

#define RENDERER 1

int main()
{

	using namespace cosmo;
	using namespace graphics;
	using namespace maths;

	Window window("Cosmo", 960, 580);

	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Cosmo-core/src/shaders/basic.vert", "Cosmo-core/src/shaders/basic.frag");
	shader.enabled();
	shader.set_uniform_mat4("pr_matrix", ortho);
	
	std::vector<Renderable2D*> sprites;

	srand(time(NULL));

	for (float y = 0; y < 9.0f; y += 0.05)
	{
		for (float x = 0; x < 16.0f; x += 0.05)
		{
			sprites.push_back(new 
#if RENDERER
				Sprite(x, y, 0.04f, 0.04f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
#else
				StaticSprite(x, y, 0.04f, 0.04f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1), shader));
#endif
		}
	}

#if RENDERER

	Sprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D renderer;

#else

	StaticSprite sprite(5, 5, 4, 4, maths::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 1, 2, 3, maths::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

#endif

	shader.set_uniform_4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	float count = 0.0f;
	bool dir = true;

	while (!window.closed())
	{
		window.clear();

		double x, y;
		window.get_mouse_position(x, y);

		shader.set_uniform_2f("light_pos", vec2(float(x * 16.0f / 960.0f), float(9.0f - y * 9.0f / 540.0f)));

#if RENDERER
		renderer.begin();
#endif

		for (int i = 0; i < sprites.size(); i++)
		{
			renderer.submit(sprites[i]);
		}

#if RENDERER
		renderer.end();
#endif
		renderer.flush();
		printf("Sprites: %d\n", sprites.size());
		window.update();

	}

	return 0;
}