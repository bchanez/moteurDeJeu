#include "CActor.hpp"

/*explicit*/ CActor::CActor(float positionX, float positionY)
{
  LOG("CActor Constructor\n");

  m_sprite.setOrigin(sf::Vector2f(32/2, 24));
  setPosition(positionX, positionY);

  m_key.keyUp = m_key.keyLeft = m_key.keyDown = m_key.keyRight = false;

  setTexture();
  setAnimation();
}

/*virtual*/ CActor::~CActor(void)
{
  LOG("CActor Destructor\n");
}

void CActor::setTexture(void)
{
  m_prerender.create(32*4, 32*8);

  m_prerender.clear(sf::Color::Transparent);

  sf::Sprite sprite;

  //body
  sf::Image i_Body = CResourceHolder::get().image(EImage_Name::e_Character);

  //edit Image
  //
  //

  sf::Texture t_Body;
  t_Body.loadFromImage(i_Body);
  sprite.setTexture(t_Body);
  m_prerender.draw(sprite);


  m_prerender.display();

  m_sprite.setTexture(m_prerender.getTexture());
}

// Define the character's animations
void CActor::setAnimation(void)
{
  for (unsigned int i = 0; i < NB_ANIMATION ; ++i)
    m_animation.push_back(CAnimation());

  for (int i = 0; i < 4 ; ++i)
  {
    m_animation[e_idle_bot].addFrame(sf::IntRect(i * 32, 0 * 32, 32, 32), 0.2f);
    m_animation[e_idle_left].addFrame(sf::IntRect(i * 32, 1 * 32, 32, 32), 0.2f);
    m_animation[e_idle_right].addFrame(sf::IntRect(i * 32, 2 * 32, 32, 32), 0.2f);
    m_animation[e_idle_top].addFrame(sf::IntRect(i * 32, 3 * 32, 32, 32), 0.2f);
    m_animation[e_walk_bot].addFrame(sf::IntRect(i * 32, 4 * 32, 32, 32), 0.1f);
    m_animation[e_walk_left].addFrame(sf::IntRect(i * 32, 5 * 32, 32, 32), 0.1f);
    m_animation[e_walk_right].addFrame(sf::IntRect(i * 32, 6 * 32, 32, 32), 0.1f);
    m_animation[e_walk_top].addFrame(sf::IntRect(i * 32, 7 * 32, 32, 32), 0.1f);
  }
}

void CActor::input(void)
{
  m_key.keyUp = m_key.keyLeft = m_key.keyDown = m_key.keyRight = false;
}

void CActor::update(float dt)
{
  switch (m_currentState)
  {
    case e_idle :
    {
      if( m_key.keyLeft ||  m_key.keyRight ||  m_key.keyUp ||  m_key.keyDown)
          m_currentState = e_walk;

      //orientation
      if(!(m_key.keyRight && m_key.keyLeft))
      {
          if(m_key.keyLeft) m_currentOrientation = e_left;
          if(m_key.keyRight) m_currentOrientation = e_right;
      }
      if(!(m_key.keyUp && m_key.keyDown))
      {
          if(m_key.keyUp) m_currentOrientation = e_top;
          if(m_key.keyDown) m_currentOrientation = e_bot;
      }

      // Animation update
      switch (m_currentOrientation)
      {
          case e_bot:
          {
            m_sprite.setTextureRect(m_animation[e_idle_bot].getFrame());
            break;
          }

          case e_left:
          {
            m_sprite.setTextureRect(m_animation[e_idle_left].getFrame());
            break;
          }

          case e_right:
          {
            m_sprite.setTextureRect(m_animation[e_idle_right].getFrame());
            break;
          }

          case e_top:
          {
            m_sprite.setTextureRect(m_animation[e_idle_top].getFrame());
            break;
          }

          default: break;
      }
      break;
    }

    case e_walk :
    {
      m_move_speed = WALK_SPEED;

      //deplacement
      float positionX = m_positionX;
      float positionY = m_positionY;

      if(m_key.keyLeft)
        positionX += -(m_move_speed * dt);

      if(m_key.keyRight)
        positionX += m_move_speed * dt;

      if(m_key.keyUp)
        positionY += -(m_move_speed * dt);

      if(m_key.keyDown)
        positionY += m_move_speed * dt;

      //orientation
      if(!(m_key.keyRight && m_key.keyLeft))
      {
          if(m_key.keyLeft) m_currentOrientation = e_left;
          if(m_key.keyRight) m_currentOrientation = e_right;
      }
      if(!(m_key.keyUp && m_key.keyDown))
      {
          if(m_key.keyUp) m_currentOrientation = e_top;
          if(m_key.keyDown) m_currentOrientation = e_bot;
      }

      if(sf::Vector2f(positionX, positionY) == getPosition())
      {
        m_currentState = e_idle;
      }
      else if (sf::Vector2f(positionX, positionY) != getPosition())
      {
        //Position update
        setPosition(positionX, positionY);

        // Animation update
        switch (m_currentOrientation)
        {
            case e_bot:
            {
              m_sprite.setTextureRect(m_animation[e_walk_bot].getFrame());
              break;
            }

            case e_left:
            {
              m_sprite.setTextureRect(m_animation[e_walk_left].getFrame());
              break;
            }

            case e_right:
            {
              m_sprite.setTextureRect(m_animation[e_walk_right].getFrame());
              break;
            }

            case e_top:
            {
              m_sprite.setTextureRect(m_animation[e_walk_top].getFrame());
              break;
            }

            default: break;
        }
        break;
      }

      break;
    }
    default : break;
  }
}

void CActor::setInput(bool keyUp, bool keyLeft, bool keyDown, bool keyRight)
{
    m_key.keyUp = keyUp;
    m_key.keyLeft = keyLeft;
    m_key.keyDown = keyDown;
    m_key.keyRight = keyRight;
}
