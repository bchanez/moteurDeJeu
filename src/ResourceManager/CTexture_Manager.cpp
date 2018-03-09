#include "CTexture_Manager.hpp"

/*explicit*/ CTexture_Manager::CTexture_Manager()
{
	LOG("CTexture_Manager Constructor\n");

	// stats
	addResource(ETexture_Name::e_Intro, "rsc/graphics/screen_intro.png");
	addResource(ETexture_Name::e_Menu, "rsc/graphics/screen_menu.png");
	addResource(ETexture_Name::e_Pause, "rsc/graphics/screen_pause.png");

	// button
	addResource(ETexture_Name::e_Play, "rsc/graphics/play.png");
	addResource(ETexture_Name::e_Return, "rsc/graphics/return.png");
	addResource(ETexture_Name::e_Quit, "rsc/graphics/quit.png");
}

/*virtual*/ CTexture_Manager::~CTexture_Manager()
{
	LOG("CTexture_Manager Destructor\n");
}
