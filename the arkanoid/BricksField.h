#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Ball.h"

using namespace sf;
using namespace std;

class BricksField
{
private:
	list<Brick> bricks;
	int temp;
	int playerScore;
	int columnsR, rowsR;
	Vector2f bricksSize, positionR;
	Color colorR;
	bool fieldIsEmpty = false;

public:
	BricksField(const Vector2f & size, const Vector2f & position, const Color & color, int columns, int rows);
	
	int getPlayerScore() { return playerScore; }
	bool isEmpty() { return fieldIsEmpty;}
	void Update(Ball & ball);
	void Draw(RenderWindow & window);
	void Clear();
};

