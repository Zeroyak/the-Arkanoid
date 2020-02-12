#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Entity.h"
#include "BricksField.h"
#include "Paddle.h"
#include "Game.h"

using namespace sf;
using namespace std;

int main()
{
	Clock clock;
	float deltaTime;
	int maxPlayerScore = 0;
	int change = 26;

	Font font;
	if (!font.loadFromFile("resources/sansation.ttf"))
		return EXIT_FAILURE;
	Image doomguyimage;
	doomguyimage.createMaskFromColor(Color(0, 255, 255));
	if (!doomguyimage.loadFromFile("resources/doomface.png"))
		return EXIT_FAILURE;
	
	Texture background;
	background.loadFromFile("resources/background.png");
	Sprite backgr;
	backgr.setTexture(background);
	
	Texture doomguytexture;
	doomguytexture.loadFromImage(doomguyimage);

	Text pauseMessage(Entity::textStart, font, 40);
	pauseMessage.setPosition(40.f, 190.f);
	pauseMessage.setFillColor(Color::White);
	pauseMessage.setStyle(Text::Bold);

	Text scoreOutput("", font, 20);
	scoreOutput.setFillColor(Color::Black);

	Text maxScoreOutput("", font, 20);
	maxScoreOutput.setFillColor(Color::Black);
	maxScoreOutput.setStyle(Text::Bold);

	bool isPlaying = false;

	BricksField bricksField(Vector2f(Entity::windowWidth, 200.f), Vector2f(0.f, 0.f), Color::White, 9, 7);

	while (Entity::window.isOpen())
	{
		Event event;
		while (Entity::window.pollEvent(event))
		{
			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
			{
				Entity::window.close();
				break;
			}
				
 			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Num1))
			{
				if (!isPlaying)
				{
					isPlaying = true;
					clock.restart();
					Game::createBall(Ball(10.f, Vector2f(255.0710f, 400.f), Color::Red, 240.f, 110.f));
					Game::createPaddle(Paddle(Vector2f(100.f, 10.f), Vector2f(256.f, 450.f), Color::White, 200.f));
				}
			}

			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Num2))
			{
				if (!isPlaying)
				{
					isPlaying = true;
					clock.restart();
					Game::createBall(Ball(20.f, Vector2f(255.0710f, 400.f), &doomguytexture, 240.f, 110.f, IntRect(-12 + change, 13, 25, 31)));
					Game::createPaddle(Paddle(Vector2f(100.f, 10.f), Vector2f(256.f, 450.f), Color::White, 200.f));
				}
			}
		}

		Entity::window.clear(Color(50, 200, 150));

		if (isPlaying)
		{
			ostringstream playerScore;
			playerScore << bricksField.getPlayerScore();
			scoreOutput.setString(playerScore.str());
			scoreOutput.setPosition(20.f, 450.f);
			Entity::window.draw(scoreOutput);

			if (maxPlayerScore < bricksField.getPlayerScore())
			{
				maxPlayerScore = bricksField.getPlayerScore();
				maxScoreOutput.setString("HighScore: " + to_string(maxPlayerScore));
				maxScoreOutput.setPosition(500.f, 450.f);
			}

			deltaTime = clock.restart().asSeconds();
			bricksField.Draw(Entity::window);
			Game::Draw(Entity::window);
			Entity::window.draw(maxScoreOutput);

			if (!Game::Update(deltaTime, bricksField))
			{
				isPlaying = false;
				pauseMessage.setString(Entity::textLost);
				pauseMessage.setPosition(40.f, 160.f);
				change += 26;
			}

			if (bricksField.isEmpty())
			{
				isPlaying = false;
				pauseMessage.setString(Entity::textWon);
			}
		}
		else
		{
			Entity::window.draw(backgr);
			Entity::window.draw(pauseMessage);
		}


		Entity::window.display();
	}

	return EXIT_SUCCESS;
}