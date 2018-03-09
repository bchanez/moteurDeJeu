#include "CMenu_State.hpp"
#include <iostream>

namespace State
{
  /*explicit*/ CMenu::CMenu(CApplication & application)
    : CGame_State(application)
  {
    LOG("CMenu Constructor\n");

    //Init texture
    m_menu.setTexture(CResourceHolder::get().texture(ETexture_Name::e_Menu));

    // bouton jouer
    m_listButton.push_back(std::make_unique<CButton>(& CResourceHolder::get().texture(ETexture_Name::e_Play), sf::Vector2f(860,500), sf::Vector2f(200,80)));

    // bouton quitter
    m_listButton.push_back(std::make_unique<CButton>(& CResourceHolder::get().texture(ETexture_Name::e_Quit), sf::Vector2f(860,700), sf::Vector2f(200,80)));

  }

  /*virtual*/ CMenu::~CMenu()
  {
    LOG("CMenu Destructor\n");
  }

  void CMenu::init(void)
  {
      m_key.escape = false;

      for (unsigned int i = 0; i < m_listButton.size(); ++i)
        m_listButton[i]->init();
  }

  void CMenu::input(sf::Event * event)
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

  void CMenu::update(float dt)
  {
    (void)dt;

    // update button
    for (unsigned int i = 0; i < m_listButton.size(); ++i)
      m_listButton[i]->update(dt);

    // update scene
    if (m_key.escape || m_listButton[e_quit]->action())
      CDisplay::getWindow()->close();

    if (m_listButton[e_play]->action())
    {
      m_application->initState(EState::e_playing);
      m_application->changeState(EState::e_playing);
    }
  }

  void CMenu::draw()
  {
    CDisplay::draw(m_menu);

    for (unsigned int i = 0; i < m_listButton.size(); ++i)
      CDisplay::draw(* (m_listButton[i].get()));
  }
}
