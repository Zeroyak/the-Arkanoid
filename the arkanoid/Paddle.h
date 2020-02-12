#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;
using namespace std;

class Paddle
{
private:
	RectangleShape paddle;
	float speed;

public:
	Paddle(const Vector2f & size, const Vector2f & position, const Color & color, float speed);

	void Update(float deltaTime);
	Vector2f getPosition() const { return paddle.getPosition(); }
	Vector2f getSize() const { return paddle.getSize(); }

	void Draw(RenderWindow & window);

	float left()   const { return paddle.getPosition().x - paddle.getSize().x / 2.f; }
	float rigth()  const { return paddle.getPosition().x + paddle.getSize().x / 2.f; }
	float top()    const { return paddle.getPosition().y - paddle.getSize().y / 2.f; }
	float bottom() const { return paddle.getPosition().y + paddle.getSize().y / 2.f; }
};

