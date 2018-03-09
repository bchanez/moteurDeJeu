#pragma once

#include "../ResourceManager/CResourceHolder.hpp"
#include "../Tools/DEBUG.hpp"

class CApplication;

namespace State
{
	class CGame_State
	{
	public:
		explicit CGame_State(CApplication& application);
		virtual ~CGame_State();

		virtual void init(void) = 0;
		virtual void input(sf::Event * event) = 0;
		virtual void update(float dt)	= 0;
		virtual void draw()	= 0;

	protected:
		CApplication* m_application;
	};
}
