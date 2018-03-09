#pragma once

#include "CGame_State.hpp"
#include "../CApplication.hpp"
#include "../Tools/CDisplay.hpp"
#include "../Tools/DEBUG.hpp"
#include "../Entity/CActor.hpp"

namespace State
{
	class CPlaying : public CGame_State
	{
			struct Key { bool keyUp, keyLeft, keyDown, keyRight, escape; };

		public:
			explicit CPlaying(CApplication& application);
			virtual ~CPlaying();

			void init(void) override;
			void input(sf::Event * event) override;
			void update(float dt) override;
			void draw() override;

		private:
			Key m_key;

			CActor *m_actor;
	};
}
