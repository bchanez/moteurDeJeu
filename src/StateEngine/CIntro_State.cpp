#include "CIntro_State.hpp"

namespace State
{
  /*explicit*/ CIntro::CIntro(CApplication & application)
    : CGame_State(application)
  {
    LOG("CIntro Constructor\n");

    //Init texture
    m_intro.setTexture(CResourceHolder::get().texture(ETexture_Name::e_Intro));

    //init animation
    for (int i = 0; i < 3 ; ++i)
      m_animation.addFrame(sf::IntRect(i * 1920, 0, 1920, 1080), 0.1f);
  }

  /*virtual*/ CIntro::~CIntro()
  {
    LOG("CIntro Destructor\n");
  }

  void CIntro::init(void)
  {
      m_key = false;    //Aucune touche n'est appuyée
  }

  void CIntro::input(sf::Event * event)
  {
      //Test si on appuie sur une touche
      if((* event).type == sf::Event::KeyPressed || (* event).type == sf::Event::MouseButtonPressed)
        m_key = true;
  }

  void CIntro::update(float dt)
  {
    (void)dt;

    // update scene
    m_intro.setTextureRect(m_animation.getFrame());

    if (m_key)
    {
      m_application->initState(EState::e_menu);
      m_application->changeState(EState::e_menu);
    }
  }

  void CIntro::draw()
  {
    CDisplay::draw(m_intro);
  }
}
