#include "BricksField.h"


BricksField::BricksField(const Vector2f & size, const Vector2f & position, const Color & color, int columns, int rows)
{
	playerScore = 0;
	Vector2f brickSize(size.x / columns, size.y / rows);
	bricksSize.x = size.x / columns;
	bricksSize.y = size.y / rows;
	columnsR = columns;
	rowsR = rows;
	colorR = color;
	positionR.x = position.x;
	positionR.y = position.y;

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			bricks.push_back(Brick(brickSize - Vector2f(4.f, 4.f), position + Vector2f(brickSize.x * i + 2.f, brickSize.y * j + 2.f), color));
		}
	}
}

void BricksField::Update(Ball & ball)
{
	temp = bricks.size();
	bricks.remove_if([&ball, this](const Brick & brick)->bool { return ball.checkColission(brick); });
	
	if (bricks.size() < temp)
	{
		playerScore++;
	}

	if (bricks.size() == 0)
	{
		fieldIsEmpty = true;
	}
}

void BricksField::Clear()
{
	bricks.clear();
	playerScore = 0;

	for (int i = 0; i < columnsR; i++)
	{
		for (int j = 0; j < rowsR; j++)
		{
			bricks.push_back(Brick(bricksSize - Vector2f(4.f, 4.f), positionR + Vector2f(bricksSize.x * i + 2.f, bricksSize.y * j + 2.f), colorR));
		}
	}
}

void BricksField::Draw(RenderWindow & window)
{
	for (auto &brick : bricks)
	{
		brick.Draw(window);
	}
}