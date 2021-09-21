#include "header/setPlayer.h"

Player* Player::instance = 0;
Player* Player::get_instance()
{
	if (instance == 0)
		instance = new Player();
	return instance;
}

void Player::run(string video_addr, string window_name){
	this -> video_addr = video_addr;
	this -> window_name = window_name;

	this -> open();
	this -> malloc();
	this -> create_display(); // <- maybe this func should edited :)
	this -> display_video();
}

