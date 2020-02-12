#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Brick
{
private:
	RectangleShape brick;

public:
	Brick(const Vector2f & size, const Vector2f & position, const Color & color);
	
	void Draw(RenderWindow & window);

	float left()   const { return brick.getPosition().x; }
	float rigth()  const { return brick.getPosition().x + brick.getSize().x; }
	float top()    const { return brick.getPosition().y; }
	float bottom() const { return brick.getPosition().y + brick.getSize().y; }
};

