#include "Pause.h"

Pause::Pause(const int size, const Vector2f & position, const Color & color, string text)
{
	font.loadFromFile("resources/sansation.ttf");

	pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(size);
	pauseMessage.setPosition(position);
	pauseMessage.setFillColor(color);
	pauseMessage.setString(text);
}

void Pause::Draw(RenderWindow & window)
{
	window.draw(pauseMessage);
}
