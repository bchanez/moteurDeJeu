#pragma once

#include "CGame_State.hpp"
#include "../CApplication.hpp"
#include "../Tools/CDisplay.hpp"
#include "../Tools/CButton.hpp"
#include "../Tools/DEBUG.hpp"

namespace State
{
	class CPause : public CGame_State
	{
			struct Key { bool escape; };

		public:
			explicit CPause(CApplication& application);
			virtual ~CPause();

			void init(void) override;
			void input(sf::Event * event) override;
			void update(float dt) override;
			void draw() override;

		private:
			Key m_key;

			sf::Sprite m_pause;

			enum EButton {e_retour, e_quitter};
			std::vector<std::unique_ptr<CButton>> m_listButton;
	};
}
