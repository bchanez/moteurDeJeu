#include "CImage_Manager.hpp"

/*explicit*/ CImage_Manager::CImage_Manager()
{
	LOG("CImage_Manager Constructor\n");

	//Character
	addResource(EImage_Name::e_Character, "rsc/graphics/character.png");
}

/*virtual*/ CImage_Manager::~CImage_Manager()
{
	LOG("CImage_Manager Destructor\n");
}
