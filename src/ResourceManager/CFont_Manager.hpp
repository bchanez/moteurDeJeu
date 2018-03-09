#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "CResourceManager.hpp"
#include "../Tools/DEBUG.hpp"

enum class EFont_Name
{
};

class CFont_Manager : public CResourceManager<EFont_Name, sf::Font>
{
	public:
		explicit CFont_Manager();
		virtual ~CFont_Manager();

	private:
		std::map <EFont_Name, sf::Font> m_fonts;
};
