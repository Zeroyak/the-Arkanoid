#include "Paddle.h"


Paddle::Paddle(const Vector2f & size, const Vector2f & position, const Color & color, float speed)
{
	paddle.setSize(size);
	paddle.setPosition(position);
	paddle.setFillColor(color);
	paddle.setOrigin(size.x / 2.f, size.y / 2.f);

	this->speed = speed;
}

void Paddle::Update(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Left) && paddle.getPosition().x - paddle.getSize().x / 2 > 0.f)
		paddle.move(-speed * deltaTime, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Right) && paddle.getPosition().x + paddle.getSize().x / 2 < Entity::windowWidth)
		paddle.move(speed * deltaTime, 0.f);
}

void Paddle::Draw(RenderWindow & window)
{
	window.draw(paddle);
}

