#include "Brick.h"

Brick::Brick(const Vector2f & size, const Vector2f & position, const Color & color)
{
	brick.setSize(size);
	brick.setPosition(position);
	brick.setFillColor(color);
}

void Brick::Draw(RenderWindow & window)
{
	window.draw(brick);
}