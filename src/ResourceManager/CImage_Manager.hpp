#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "CResourceManager.hpp"
#include "../Tools/DEBUG.hpp"


enum class EImage_Name
{
	// character
	e_Character
};

class CImage_Manager : public CResourceManager<EImage_Name, sf::Image>
{
	public:
		explicit CImage_Manager();
		virtual ~CImage_Manager();

	private:
		std::map <EImage_Name, sf::Image> m_images;

};
