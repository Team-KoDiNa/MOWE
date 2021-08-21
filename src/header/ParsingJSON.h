#pragma once

#include<iostream>
#include<fstream>
#include<map>
#include"json/json.h"
#include<string.h>

using namespace std;

class parseJSON{
public:
    parseJSON();

    int init(string fileDir);
    //read json
    int read_json(string fileDir);
    
    // //get value from json
    // int get_height();
    // int get_weight();
    // string get_wallpaperFileName();
    // string get_dir();
    // string get_Extension();
    // bool isWeb();
    // string get_userSetting();

protected:
    string wallpaperFileName,fileExtension,wallpaperDir;
    int h,w;
    bool isWeb;
    Json::Value userSetting;
};
