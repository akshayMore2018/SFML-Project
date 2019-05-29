#include "PlayerProfile.h"
PlayerProfile* PlayerProfile::instance = 0;

PlayerProfile::PlayerProfile()
{
}
PlayerProfile * PlayerProfile::getInstance()
{
	if (!instance)
		instance= new PlayerProfile();
	return instance;
}
