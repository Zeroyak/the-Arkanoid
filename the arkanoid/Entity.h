#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

constexpr auto M_PI = 3.14159265358979323846;

class Entity
{
private:
	Entity() = delete;

public:
	static const float windowWidth, windowHeight;
	static const string textStart;
	static const string textLost;
	static const string textWon;
	static RenderWindow window;
};

