#pragma once

#include "CGame_State.hpp"
#include "../CApplication.hpp"
#include "../Tools/CDisplay.hpp"
#include "../Tools/DEBUG.hpp"
#include "../Tools/CAnimation.hpp"

namespace State
{
	class CIntro : public CGame_State
	{
		public:
			explicit CIntro(CApplication& application);
			virtual ~CIntro();

			void init(void) override;
			void input(sf::Event * event) override;
			void update(float dt) override;
			void draw() override;

		private:
			bool m_key;

			sf::Sprite m_intro;
			CAnimation m_animation;
	};
}
