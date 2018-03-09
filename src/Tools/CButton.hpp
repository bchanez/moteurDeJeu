#pragma once

#include <SFML/Graphics.hpp>
#include "CDrawable.hpp"
#include "CAnimation.hpp"
#include "../ResourceManager/CResourceHolder.hpp"
#include "CCollision.hpp"
#include "DEBUG.hpp"

class CButton : public CDrawable
{
  struct Mouse { bool clicked; sf::Vector2f position; };

  public:
    explicit CButton(const sf::Texture * texture, sf::Vector2f position,  sf::Vector2f size);
    virtual ~CButton(void);

    void setTexture(const sf::Texture * texture);
    void setAnimation(void);

    void inputMousePosition(sf::Vector2f position);
    void inputMouseclicked(bool clicked);
    bool action(void);

    void init(void);
    void update(float dt);

  private:
    enum Estate {e_normal, e_hovered, e_cliked};
    unsigned int m_state;

		bool m_action;

    std::vector<CAnimation> m_animation;
    unsigned int m_nb_animation = 3;

    sf::Vector2f m_position;
    sf::Vector2f m_size;

    Mouse mouse;
};
