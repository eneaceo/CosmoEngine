#include "Cosmo-core/src/graphics/window.h"
#include "Cosmo-core/src/maths/maths.h"
#include "Cosmo-core/src/graphics/shader.h"

#include "Cosmo-core/src/graphics/buffers/buffer.h"
#include "Cosmo-core/src/graphics/buffers/index_buffer.h"
#include "Cosmo-core/src/graphics/buffers/vertex_array.h"

#include "Cosmo-core/src/graphics/renderer2D.h"
#include "Cosmo-core/src/graphics/simple2Drenderer.h"
#include "Cosmo-core/src/graphics/batchrenderer2D.h"

#include "Cosmo-core/src/graphics/static_sprite.h"
#include "Cosmo-core/src/graphics/sprite.h"

#include "Cosmo-core/src/graphics/layers/tile_layer.h"

#include <vector>
#include <time.h>
#include "Cosmo-core/src/utils/timer.h"

#define TEST_50K 0

int main()
{

	using namespace cosmo;
	using namespace graphics;
	using namespace maths;

	Window window("Cosmo!", 960, 540);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("Cosmo-core/src/shaders/basic.vert", "Cosmo-core/src/shaders/basic.frag");
	Shader* s2 = new Shader("Cosmo-core/src/shaders/basic.vert", "Cosmo-core/src/shaders/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.enabled();
	shader2.enabled();
	shader.set_uniform_2f("light_pos", vec2(4.0f, 1.5f));
	shader2.set_uniform_2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(&shader);

#if TEST_50K
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new Sprite(x, y, 0.05f, 0.05f, maths::vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1)));
		}
	}
#else
	Sprite* button = new Sprite(-15.0f, 5.0f, 6, 3, maths::vec4(1, 1, 1, 1));
	layer.add(button);
	
	layer.add(new Sprite(0.5f, 0.5f, 5.0f, 2.0f, maths::vec4(1, 0, 1, 1)));

#endif

	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, maths::vec4(1, 0, 1, 1)));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.get_mouse_position(x, y);
		shader.enabled();
		shader.set_uniform_2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		//shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		//shader.setUniform2f("light_pos", vec2(-8, -3));
		shader2.enabled();

		layer.render();
		//	layer2.render();

		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}