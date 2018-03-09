#include "CPlaying_State.hpp"

namespace State
{
	/*explicit*/ CPlaying::CPlaying(CApplication & application)
	: CGame_State(application)
	{
		LOG("CPlaying Constructor\n");
	}

	/*virtual*/ CPlaying::~CPlaying()
	{
		LOG("CPlaying Destructor\n");
		delete(m_actor);
	}

	void CPlaying::init(void)
	{
		m_key.keyUp = m_key.keyLeft = m_key.keyDown = m_key.keyRight = m_key.escape = false;

		m_actor = new CActor(0.f, 0.f);
		// centre la vue sur la position du personnage (Diviser par deux et zoomé)
		CDisplay::getView()->setSize(1920.f/2, 1080.f/2);
		CDisplay::getView()->setCenter((*m_actor).getPosition());
		CDisplay::getWindow()->setView(* CDisplay::getView());
	}

	void CPlaying::input(sf::Event * event)
	{
		if((* event).type == sf::Event::KeyPressed)
		{
			if ((* event).key.code == sf::Keyboard::Z
			|| (* event).key.code == sf::Keyboard::W)
			m_key.keyUp = true;

			if ((* event).key.code == sf::Keyboard::Q
			|| (* event).key.code == sf::Keyboard::A)
			m_key.keyLeft = true;

			if ((* event).key.code == sf::Keyboard::S)
			m_key.keyDown = true;

			if ((* event).key.code == sf::Keyboard::D)
			m_key.keyRight = true;

			if((* event).key.code == sf::Keyboard::Escape)
			m_key.escape = true;
		}


		if((* event).type == sf::Event::KeyReleased)
		{
			if ((* event).key.code == sf::Keyboard::Z
			|| (* event).key.code == sf::Keyboard::W)
			m_key.keyUp = false;

			if ((* event).key.code == sf::Keyboard::Q
			|| (* event).key.code == sf::Keyboard::A)
			m_key.keyLeft = false;

			if ((* event).key.code == sf::Keyboard::S)
			m_key.keyDown = false;

			if ((* event).key.code == sf::Keyboard::D)
			m_key.keyRight = false;

			if ((* event).key.code == sf::Keyboard::Escape)
			m_key.escape = false;
		}

		(*m_actor).setInput(m_key.keyUp, m_key.keyLeft, m_key.keyDown, m_key.keyRight);
	}

	void CPlaying::update(float dt)
	{
		//update de la scene
		if (m_key.escape)
		{
			m_application->initState(EState::e_pause);
			m_application->changeState(EState::e_pause);
			return;
		}

		(*m_actor).update(dt);
	}

	void CPlaying::draw()
	{
		CDisplay::draw((*m_actor));
	}
}
