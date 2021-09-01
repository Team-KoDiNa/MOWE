#include "header/setPlayer.h"

Player* Player::instance = 0;
Player* Player::get_instance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}