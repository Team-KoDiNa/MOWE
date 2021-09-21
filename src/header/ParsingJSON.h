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

    int returnHeight(){ return h; };
    int returnWeight(){ return w; };

    string returnFileExtension(){ return fileExtension; };
    string returnWallpaperDir(){ return wallpaperDir; };

protected:
    static parseJSON* instance;
    string wallpaperFileName,fileExtension;
    string wallpaperDir;
    int h,w;
    bool isWeb;
    Json::Value userSetting;
};
