#include "header/ParsingJSON.h"

parseJSON::parseJSON(){
    //nothing
}

int parseJSON::init(string fileDir){
    int err = parseJSON::read_json(fileDir);
    if(err == 1) return 1;
    return 0;
}

int parseJSON::read_json(string fileDir){
    ifstream fin;
    fin.open(fileDir,std::ios::in);
    string str;
    str.assign(istreambuf_iterator<char>(fin), istreambuf_iterator<char>());

    Json::Reader reader;
    Json::Value root;

    if(reader.parse(str,root) == false){
        std::cerr << "Failed to parse JSON File : " << reader.getFormattedErrorMessages() <<endl;
        return 1;
    }
    else {
        this -> h = root["height"].asInt();
        this -> w = root["weight"].asInt();
        this -> wallpaperFileName = root["wallpaperFileName"].asString();
        this -> fileExtension = root["fileExtenstion"].asString();
        this -> wallpaperDir = root["wallpaperDir"].asString();
        this -> userSetting = root["userSetting"];
    }
    return 0;
}