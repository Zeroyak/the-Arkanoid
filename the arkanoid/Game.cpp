#include "Game.h"

Ball * Game::ball = nullptr;
Paddle * Game::paddle = nullptr;

bool Game::Update(float deltaTime, BricksField & bricksField)
{
	if (paddle != nullptr)
		paddle->Update(deltaTime);

	if (ball != nullptr && ball->exist())
	{
		ball->Update(deltaTime);
		ball->checkColission(*paddle);
		bricksField.Update(*ball);
		return true;
	}
	else
	{
		delete ball;
		ball = nullptr;
		delete paddle;
		paddle = nullptr;
		bricksField.Clear();
		return false;
	}
}

void Game::Draw(RenderWindow & window)
{
	if (ball != nullptr)
		ball->Draw(window);

	if (paddle != nullptr)
		paddle->Draw(window);
}