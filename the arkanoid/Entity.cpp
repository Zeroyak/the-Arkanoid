#include "Entity.h"


const float Entity::windowWidth = 640.f;
const float Entity::windowHeight = 480.f;

const string Entity::textStart = "Welcome to SFML arkanoid!\nPress 1 or 2 to start the game!";
const string Entity::textLost = "You lost!\nPress 1 or 2 to restart or\nescape to exit.";
const string Entity::textWon = "You win!\nGoodbye!";

RenderWindow Entity::window(VideoMode(windowWidth, windowHeight), "The Arkanoid", Style::Close | Style::Titlebar);
