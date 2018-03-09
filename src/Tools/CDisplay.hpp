#pragma once

#include "SFML/Graphics.hpp"

namespace CDisplay
{
	void init();

	void clear();
	void clear(sf::Color col);
	void display();

	void draw(const sf::Drawable& drawable);
	void draw(const sf::Drawable& drawable, const sf::Texture& texture);

	bool isOpen();

	sf::RenderWindow * getWindow();
	sf::View * getView();

	// Taille de la fenetre en WINDOWED : 960x540 pixels
	constexpr int WINDOWED_SCREEN_WIDTH = 960;
	constexpr int WINDOWED_SCREEN_HEIGHT = 540;
	// Taille de la fenetre en FULLSCREEN : 1920x1080 pixels
	constexpr int FULL_SCREEN_WIDTH = 1920;
	constexpr int FULL_SCREEN_HEIGHT = 1080;

}
