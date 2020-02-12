#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Pause
{
private:
	Text pauseMessage;
	Font font;

public:
	Pause(const int size, const Vector2f & position, const Color & color, string text);

	void Draw(RenderWindow & window);
};

