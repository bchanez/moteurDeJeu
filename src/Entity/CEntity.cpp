#include "CEntity.hpp"

/*explicit*/ CEntity::CEntity(void)
{
  LOG("CEntity Constructor\n");

  m_sprite.setPosition(sf::Vector2f(0.f, 0.f));

  m_positionX = 0.f; m_positionY = 0.f;
  m_move_speed = 0;

  m_currentState = e_idle;
  m_currentOrientation = 0;
}

/*virtual*/ CEntity::~CEntity(void)
{
  LOG("CEntity Destructor\n");
}

void CEntity::setPosition(float positionX, float positionY)
{
  m_positionX = positionX; m_positionY = positionY;
  m_sprite.setPosition(sf::Vector2f(positionX, positionY));
}

sf::Vector2f CEntity::getPosition(void)
{
  return sf::Vector2f(m_positionX, m_positionY);
}
