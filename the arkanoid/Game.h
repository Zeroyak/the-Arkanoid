#pragma once

#include <SFML/Graphics.hpp>
#include "BricksField.h"
#include "Pause.h"

using namespace sf;
using namespace std;

class Game
{
private:
	static Ball * ball;
	static Paddle * paddle;
	Game() = delete;

public:
	static void createBall(const Ball & bal) { ball = new Ball(bal); }
	static void createPaddle(const Paddle & paddl) { paddle = new Paddle(paddl); }
	static bool Update(float deltaTime, BricksField & bricksField);
	static void Draw(RenderWindow & window);
};

