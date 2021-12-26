#pragma once

#include <iostream>
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"

using namespace std;

class Player{
    public:
        static Player* get_instance();

        void run(string video_addr, string window_name);
        void clear();

	    // static int getAudioPacket(AudioPacket*, AVPacket*, int); <- maybe add it later :((

    private:
        static Player* instance;
        Player() {}

        void open();

        int malloc(void);
        int display_video(void);
        int create_display(void);

        int get_video_stream(void);

        int read_audio_video_codec(void);

        int videoStream = 0;
	    int audioStream = 0;

        std::string video_addr;
        std::string window_name;

        AVCodecParameters* pCodecParameters = NULL;
        AVCodecParameters* pCodecAudioParameters = NULL;

        AVFormatContext *pFormatCtx = NULL;

        AVCodecContext* pCodecCtx = NULL;
        AVCodecContext* pCodecAudioCtx = NULL;

        AVCodec* pCodec = NULL;
        AVCodec* pAudioCodec = NULL;
        AVFrame* pFrame = NULL;
        AVFrame* pFrameRGB = NULL;

        uint8_t* buffer = NULL;

        struct SwsContext* sws_ctx = NULL;

};
