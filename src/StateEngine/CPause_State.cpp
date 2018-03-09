#include "CPause_State.hpp"

namespace State
{
  /*explicit*/ CPause::CPause(CApplication & application)
    : CGame_State(application)
  {
    LOG("CPause Constructor\n");

    // init texture
    m_pause.setTexture(CResourceHolder::get().texture(ETexture_Name::e_Pause));

    // bouton retour
    m_listButton.push_back(std::make_unique<CButton>(& CResourceHolder::get().texture(ETexture_Name::e_Return), sf::Vector2f(860,500), sf::Vector2f(200,80)));

    // bouton quitter
    m_listButton.push_back(std::make_unique<CButton>(& CResourceHolder::get().texture(ETexture_Name::e_Quit), sf::Vector2f(860,700), sf::Vector2f(200,80)));

  }

  /*virtual*/ CPause::~CPause()
  {
    LOG("CPause Destructor\n");
  }

  void CPause::init(void)
  {
      m_key.escape = false;

      for (unsigned int i = 0; i < m_listButton.size(); ++i)
        m_listButton[i]->init();

      //Recentre la vue (différente de en jeu)
      CDisplay::getView()->setSize(1920.f, 1080.f);
      CDisplay::getView()->setCenter(1920.f/2, 1080.f/2);
      CDisplay::getWindow()->setView(* CDisplay::getView());
  }

  void CPause::input(sf::Event * event)
  {
    if((* event).type == sf::Event::KeyPressed)
      if ((* event).key.code == sf::Keyboard::Escape)
        m_key.escape = true;

    if((* event).type == sf::Event::KeyReleased)
      if ((* event).key.code == sf::Keyboard::Escape)
        m_key.escape = false;

    if ((* event).type == sf::Event::MouseMoved)
      for (unsigned int i = 0; i < m_listButton.size(); ++i)
        m_listButton[i]->inputMousePosition(CDisplay::getWindow()->mapPixelToCoords(sf::Vector2i((* event).mouseMove.x, (* event).mouseMove.y), * CDisplay::getView()));

    if ((* event).type == sf::Event::MouseButtonPressed)
        if ((* event).mouseButton.button == sf::Mouse::Left)
          for (unsigned int i = 0; i < m_listButton.size(); ++i)
            m_listButton[i]->inputMouseclicked(true);

    if ((* event).type == sf::Event::MouseButtonReleased)
        if ((* event).mouseButton.button == sf::Mouse::Left)
          for (unsigned int i = 0; i < m_listButton.size(); ++i)
            m_listButton[i]->inputMouseclicked(false);
  }

  void CPause::update(float dt)
  {
    (void)dt;

    // update button
    for (unsigned int i = 0; i < m_listButton.size(); ++i)
      m_listButton[i]->update(dt);

    // update scene
    if (m_key.escape || m_listButton[e_quitter]->action())
    {
      m_application->initState(EState::e_menu);
      m_application->changeState(EState::e_menu);
    }

    if (m_listButton[e_retour]->action())
    {
      m_application->initState(EState::e_playing);
      m_application->changeState(EState::e_playing);
    }
  }

  void CPause::draw()
  {
    CDisplay::draw(m_pause);

    for (unsigned int i = 0; i < m_listButton.size(); ++i)
      CDisplay::draw(* (m_listButton[i].get()));
  }
}
