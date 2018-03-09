#pragma once

#include <SFML/Graphics.hpp>

namespace CCollision
{
	bool collision(sf::FloatRect box, sf::Vector2f dot);
	bool collision(sf::FloatRect box1, sf::FloatRect box2);
}
