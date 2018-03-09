#pragma once

#include <SFML/Graphics.hpp>
#include "../Tools/CDrawable.hpp"
#include "../Tools/CAnimation.hpp"
#include "../Tools/DEBUG.hpp"

class CEntity : public CDrawable
{
  public:
    explicit CEntity(void);
    virtual ~CEntity(void);

    virtual void setTexture(void) = 0;
    virtual void setAnimation(void) = 0;

    virtual void input(void) = 0;
    virtual void update(float dt) = 0;

    void setPosition(float positionX, float positionY);
    sf::Vector2f getPosition(void);

  protected:
    float m_positionX, m_positionY;
    unsigned int m_move_speed;

    enum Estate {e_idle};
    unsigned int m_currentState;

    enum Eorientation {};
    unsigned int m_currentOrientation;

    enum EAnimation {};
    const unsigned int NB_ANIMATION = 0;
    std::vector<CAnimation> m_animation;
};
