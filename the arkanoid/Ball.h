#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Paddle.h"

using namespace sf;
using namespace std;

class Ball
{
private:
	CircleShape ball;
	float speed;
	Vector2f velocity;

	void setAngle(float ang);
	float getAngle();

public:
	Ball(float radius, const Vector2f & position, const Color & color, float speed, float angle);
	Ball(float radius, const Vector2f & position, const Texture * texture, float speed, float angle, const IntRect & intrect);
	
	bool checkColission(const Brick & brick);
	bool checkColission(const Paddle & paddle);
	bool exist() { return bottom() <= Entity::windowHeight; }

	void Update(float deltaTime);

	void Draw(RenderWindow & window);

	float left()   const { return ball.getPosition().x - ball.getRadius(); }
	float rigth()  const { return ball.getPosition().x + ball.getRadius(); }
	float top()    const { return ball.getPosition().y - ball.getRadius(); }
	float bottom() const { return ball.getPosition().y + ball.getRadius(); }

	float getX() const { return ball.getPosition().x; }
	float getY() const { return ball.getPosition().y; }
	Vector2f getPosition() const { return ball.getPosition(); }
	float getRadius() const { return ball.getRadius(); }
	Vector2f getVelocity() const { return velocity; }
};

