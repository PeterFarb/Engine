#include <Engine/Engine.h>

int main()
{
	Engine engine;

	engine.Initialize(1920,1080,"SuperGame");

	while(true){
		engine.Update();
		engine.Render();
	}


	return 0;
}
