#ifndef __HONEYLemon_SD_CARD_CPP__
#define __HONEYLemon_SD_CARD_CPP__

#include "HONEYLemon.h"

/* Micro SD Card */
bool HONEYLemon::createFile(String filename){
    bool success = false;
    if(!this->modeMicroSDCard){
        DEBUG_PRINTLN("Please Check Micro SD Card");
    }else{
        DEBUG_PRINTLN("Create File :"+filename);
        String path = "/"+filename;
        File file = SD.open(path.c_str(), FILE_WRITE);
        if(!file)success=false;
        if(file.print("")){
            success=false;
        }else{
            success=false;
        }
        file.close();
    }
    return success;
}
bool HONEYLemon::writeFileln(String filename, String text){
    return this->writeFile(filename,text+"\n");
}
bool HONEYLemon::writeFile(String filename, String text){
    bool success = false;
    if(!this->modeMicroSDCard){
        DEBUG_PRINTLN("Please Check Micro SD Card");
    }else{
        DEBUG_PRINTLN("Write File: "+filename+" -> "+text);
        String path = "/"+filename;
        File file = SD.open(path.c_str(), FILE_APPEND);
        if(!file)success=false;
        if(file.print(text.c_str())){
            success=true;
        }else{
            success=false;
        }
        file.close();
    }
    return success;
}
String HONEYLemon::readFile(String filename){
    bool success = false;
    String msg="";
    if(!this->modeMicroSDCard){
        DEBUG_PRINTLN("Please Check Micro SD Card");
    }else{
        DEBUG_PRINTLN("Read File: "+filename);
        String path = "/"+filename;
        File file = SD.open(path.c_str());
        if(!file){
            success = false;
        }else{
            while(file.available()){
                msg += (char)file.read();
            }
            success = true;
        }
        file.close();
    }
    if(success){
        return msg;
    }else{
        return "";
    }
}
bool HONEYLemon::renameFile(String old_filename,String new_filename){
    if(!this->modeMicroSDCard){
        DEBUG_PRINTLN("Please Check Micro SD Card");
        return false;
    }else{
        DEBUG_PRINTLN("Rename File: "+old_filename+" to File: "+new_filename);
        String path1 = "/"+old_filename;
        String path2 = "/"+new_filename;
        if(SD.rename(path1.c_str(),path2.c_str())){
            return true;
        }else{
            return false;
        }
    }
}
bool HONEYLemon::removeFile(String filename){
    if(!this->modeMicroSDCard){
        DEBUG_PRINTLN("Please Check Micro SD Card");
        return false;
    }else{
        DEBUG_PRINTLN("Remove File: "+filename);
        String path = ("/"+filename).c_str();
        if(SD.remove(path.c_str())){
            return true;
        }else{
            return false;
        }
    }
}
bool HONEYLemon::HONEYLemonUpdateFirmwareWithSDCard(String filename) {
    if(!this->modeMicroSDCard){
        DEBUG_PRINTLN("Please Check Micro SD Card");
        return false;
    }else{
        DEBUG_PRINTLN("HONEYLemon Update Firmware with Micro-SD Card: "+filename);
        bool success = false;
        File updateBin = SD.open(("/"+filename).c_str());
        if (updateBin) {
            if(updateBin.isDirectory()){
                DEBUG_PRINTLN("Firmware Error, "+filename+" is not a file");
                updateBin.close();
            }else{
                size_t updateSize = updateBin.size();
                if (updateSize > 0) {
                    DEBUG_PRINTLN("Firmware Start Update -> "+filename);
                    if (Update.begin(updateSize)) {
                        Update.writeStream(updateBin);
                        if (Update.end() && Update.isFinished()){
                            success=true;
                            DEBUG_PRINTLN("Firmware Update Success!!!");
                        }
                    }
                }
            }
            updateBin.close();
            DEBUG_PRINTLN("Firmware Rename File "+filename+" -> "+filename+".backup");
            SD.rename(("/"+filename).c_str(),("/"+filename+".backup").c_str());
        }
        if(!success)DEBUG_PRINTLN("Firmware Error Update!!!");
        return success;
    }
}

#endif