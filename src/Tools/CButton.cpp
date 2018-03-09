#include "CButton.hpp"

/* explicit */ CButton::CButton(const sf::Texture * texture, sf::Vector2f position, sf::Vector2f size)
{
  LOG("CButton Constructor\n");

  m_position = position;
  m_sprite.setPosition(m_position);
  m_size = size;

  setTexture(texture);
  setAnimation();

  m_state = e_normal;
}

/* virtual */ CButton::~CButton(void)
{
  LOG("CButton Destructor\n");
}

void CButton::setTexture(const sf::Texture * texture)
{
  m_sprite.setTexture(* texture);
}

void CButton::setAnimation(void)
{
  for (unsigned int i = 0; i < m_nb_animation ; ++i)
    m_animation.push_back(CAnimation());

  m_animation[e_normal].addFrame(sf::IntRect(0, m_size.y * 0, m_size.x, m_size.y), 0.1f);
  m_animation[e_hovered].addFrame(sf::IntRect(0, m_size.y * 1, m_size.x, m_size.y), 0.1f);
  m_animation[e_cliked].addFrame(sf::IntRect(0, m_size.y * 2, m_size.x, m_size.y), 0.1f);

  m_sprite.setTextureRect(m_animation[e_normal].getCurrentFrame());
}

void CButton::inputMousePosition(sf::Vector2f position)
{
  mouse.position = position;
}

void CButton::inputMouseclicked(bool clicked)
{
  mouse.clicked  = clicked;
}

bool CButton::action(void)
{
  return m_action && m_state == e_hovered && CCollision::collision(sf::FloatRect(m_position, m_size), mouse.position);
}

void CButton::init(void)
{
  m_state = e_normal;
  mouse.clicked = false;
  mouse.position = sf::Vector2f(0,0);
  m_action = false;
}

void CButton::update(float dt)
{
  (void) dt;

  switch (m_state)
  {
    case e_normal :
    {
      if(CCollision::collision(sf::FloatRect(m_position, m_size), mouse.position))
        m_state = e_hovered;

      m_action = false;

      m_sprite.setTextureRect(m_animation[e_normal].getFrame());
    }
    break;

    case e_hovered :
    {
      if(mouse.clicked)
        m_state = e_cliked;
      else if(!CCollision::collision(sf::FloatRect(m_position, m_size), mouse.position))
        m_state = e_normal;

      m_sprite.setTextureRect(m_animation[e_hovered].getFrame());
    }
    break;

    case e_cliked :
    {
      if(!mouse.clicked)
        m_state = e_hovered;

      m_action = true;

      m_sprite.setTextureRect(m_animation[e_cliked].getFrame());
    }
    break;

    default : {} break;
  }
}
