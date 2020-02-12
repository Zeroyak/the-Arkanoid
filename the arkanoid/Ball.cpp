#include "Ball.h"

Ball::Ball(float radius, const Vector2f & position, const Color & color, float speed, float angle)
{
	ball.setRadius(radius);
	ball.setPosition(position);
	ball.setFillColor(color);
	ball.setOrigin(radius, radius);

	this->speed = speed;
	setAngle(angle);
}

Ball::Ball(float radius, const Vector2f & position, const Texture * texture, float speed, float angle, const IntRect & intrect)
{
	ball.setRadius(radius);
	ball.setPosition(position);
	ball.setTexture(texture);
	ball.setOrigin(radius, radius);

	ball.setTextureRect(intrect);

	this->speed = speed;
	setAngle(angle);
}

void Ball::setAngle(float angle)
{
	velocity.x = speed * cos(angle * M_PI / 180);
	velocity.y = -speed * sin(angle * M_PI / 180);
}
float Ball::getAngle()
{
	// angle in range [-180; 180]
	float angle = atan2(-velocity.y, velocity.x) * 180 / M_PI;
	// angle in range [0; 360]
	if (angle < 0.f)
		angle += 360.f;
	return angle;
}

bool Ball::checkColission(const Brick & brick)
{
	if ((getX() >= brick.left() && getX() <= brick.rigth()) ||
		(getY() >= brick.top() && getY() <= brick.bottom()))
	{
		if (left() < brick.rigth() && rigth() > brick.left() && top() < brick.bottom() && bottom() > brick.top())
		{
			if (getX() < brick.left() || getX() > brick.rigth())
			{
				velocity.x *= -1;
			}
			else
			{
				velocity.y *= -1;
			}
			return true;
		}
	}
	else
	{
		auto distance = [](Vector2f x1, Vector2f x2)->float { return sqrt(pow(x1.x - x2.x, 2) + pow(x1.y - x2.y, 2)); };

		Vector2f corner;

		if (distance(getPosition(), Vector2f(brick.left(), brick.top())) <= getRadius())
			corner = Vector2f(brick.left(), brick.top());
		else if (distance(getPosition(), Vector2f(brick.left(), brick.bottom())) <= getRadius())
			corner = Vector2f(brick.left(), brick.bottom());
		else if (distance(getPosition(), Vector2f(brick.rigth(), brick.top())) <= getRadius())
			corner = Vector2f(brick.rigth(), brick.top());
		else if (distance(getPosition(), Vector2f(brick.rigth(), brick.bottom())) <= getRadius())
			corner = Vector2f(brick.rigth(), brick.bottom());
		else
			return false;

		float a = (-getY() + corner.y) / (getX() - corner.x);
		a = -1 / a;
		float alpha = atan(a) * 180 / M_PI;
		if (alpha < 0)
			alpha += 180;
		float beta = getAngle();

		// angle in range [0; 360]
		float angle = 2 * alpha - beta;
		// angle in range [-180; 180]
		if (angle > 180.f)
			angle -= 360.f;
		else if (angle <= -180.f)
			angle += 360.f;

		if (angle <= 0.f && angle > -8.f)
			angle = -8.f;
		else if (angle > 0.f && angle < 8.f)
			angle = 8.f;

		setAngle(angle);

		return true;
	}

	return false;
}

bool Ball::checkColission(const Paddle & paddle)
{
	if (left() < paddle.rigth() && rigth() > paddle.left() && top() < paddle.bottom() && bottom() >= paddle.top())
	{
		/*float minAngle = 120.f, maxAngle = 60.f;
		float percantage = getX() - paddle.left() / paddle.getSize().x;
		float angle = minAngle - (minAngle - maxAngle) * percantage;
		setAngle(angle);*/

		float deviation = 50.f;
		bool leftSide = getX() < paddle.getPosition().x;
		float distanceFromCenter = abs(getX() - paddle.getPosition().x);
		float percantage = distanceFromCenter / (paddle.getSize().x / 2.f);
		float angle = 90.f - percantage * deviation * (leftSide ? -1.f : 1.f);
		setAngle(angle);

		return true;
	}
	return false;
}

void Ball::Update(float deltaTime)
{
	ball.move(velocity * deltaTime);
	if (left() < 0.f)
		velocity.x = -velocity.x;
	if (rigth() > Entity::windowWidth)
		velocity.x = -velocity.x;
	if (top() < 0.f)
		velocity.y = -velocity.y;
}

void Ball::Draw(RenderWindow & window)
{
	window.draw(ball);
}