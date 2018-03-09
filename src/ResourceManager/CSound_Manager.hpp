#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include "../Tools/DEBUG.hpp"
#include "CResourceManager.hpp"

enum class ESound_Name
{
};

class CSound_Manager : public CResourceManager<ESound_Name, sf::SoundBuffer>
{
	public:
		explicit CSound_Manager();
		virtual ~CSound_Manager();

	private:
		std::map <ESound_Name, sf::SoundBuffer> m_sounds;

};
