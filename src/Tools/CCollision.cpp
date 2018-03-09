#include "CCollision.hpp"

namespace CCollision
{
  bool collision(sf::FloatRect box, sf::Vector2f dot)
  {
    return box.contains(dot);
  }

  bool collision(sf::FloatRect box1, sf::FloatRect box2)
  {
    return box1.intersects(box2);
  }
}
