#include "CApplication.hpp"

/*explicit*/ CApplication::CApplication(void)
{
	LOG("CApplication Constructor\n");
	CDisplay::init();	//Création fenêtre

	//Insertion tout les états possible (intro, menu, en jeu, pause)
	m_state.insert(std::make_pair(EState::e_intro, std::make_unique<State::CIntro>(*this)));
	m_state.insert(std::make_pair(EState::e_menu, std::make_unique<State::CMenu>(*this)));
	m_state.insert(std::make_pair(EState::e_playing, std::make_unique<State::CPlaying>(*this)));
	m_state.insert(std::make_pair(EState::e_pause, std::make_unique<State::CPause>(*this)));

	// le premier etat est l'intro
	m_currentScene = EState::e_intro;
	m_state[m_currentScene]->init();
}

/*virtual*/ CApplication::~CApplication(void)
{
	LOG("CApplication Destructor\n");
}

void CApplication::runMainLoop(void)
{
	while (CDisplay::isOpen())	//Fenetre ouverte
	{
		float dt = m_clock.restart().asSeconds();
		sf::Event event;

		CDisplay::clear();

		while (CDisplay::getWindow()->pollEvent(event))
			m_state[m_currentScene]->input(& event);
		m_state[m_currentScene]->update(dt);
		m_state[m_currentScene]->draw();

		CDisplay::display();
	}
}

void CApplication::initState(EState state)
{
	m_state[state]->init();
}

void CApplication::changeState(EState state)
{
	m_currentScene = state;
}
