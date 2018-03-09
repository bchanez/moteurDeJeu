#pragma once

#include "CTexture_Manager.hpp"
#include "CImage_Manager.hpp"
#include "CFont_Manager.hpp"
#include "CSound_Manager.hpp"
#include "../Tools/DEBUG.hpp"

class CResourceHolder
{
	public:
		explicit CResourceHolder();
		virtual ~CResourceHolder();

		static const CResourceHolder& get();

		const sf::Texture& texture(ETexture_Name name) const;
		const sf::Image& image(EImage_Name name) const;
		const sf::Font& font(EFont_Name name) const;
		const sf::SoundBuffer& sound(ESound_Name name) const;

	private:
		CTexture_Manager m_textures;
		CImage_Manager m_images;
		CFont_Manager m_fonts;
		CSound_Manager m_sounds;
};
