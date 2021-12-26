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

void Player::open(){
	audioStream = -1;

	int res = avformat_open_input(&pFormatCtx, this->video_addr.c_str(), NULL, NULL);

	if(res != 0){
		perror("[ERROR] There is no Video to play");
	}

	res = avformat_find_stream_info(pFormatCtx, NULL);
	if (res < 0) {
		perror("[ERROR] We cannot find Video info");
	}

	videoStream = get_video_stream();
	if(videoStream == -1){
		perror("[Error] Opening your video using AVCodecParameters, probably doesnt have codecpar_type type AVMEDIA_TYPE_VIDEO");

	read_audio_video_codec();
}

void Player::clear() {
	avformat_close_input(&pFormatCtx);
	avcodec_free_context(&pCodecCtx);

	av_free(buffer);
	av_free(pFrameRGB);
	av_free(pFrame);
	avcodec_close(pCodecCtx);

	avformat_close_input(&pFormatCtx);

	delete Player::get_instance();
}

int Player::get_video_stream(void){
	int videoStream = -1;

	for(uint i = 0; i<pFormatCtx->nb_streams; i++){
		
	}
}
