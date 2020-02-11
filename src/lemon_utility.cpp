#ifndef __HONEYLemon_UTILITY_CPP__
#define __HONEYLemon_UTILITY_CPP__

#include "HONEYLemon.h"

/* Debug Function*/
void HONEYLemon::debug(Stream &serial){
    modeDebug = true;
    SERIAL_DEBUG = &serial;
    DEBUG_PRINT(this->getVersion()+"\n");
}
void HONEYLemon::DEBUG_PRINT(String _msg,bool header){
    if(modeDebug){
        if(header) SERIAL_DEBUG->print("[LEMON]: "+_msg);
        else SERIAL_DEBUG->print(_msg);
    }
}

String HONEYLemon::getVersion(){
    return "HONEYLemon library Version "+String(Version);
}

String HONEYLemon::getChipId(){
    char chipIdChar[13];
    uint64_t chipId = ESP.getEfuseMac();
    snprintf(chipIdChar, 13, "%04X%08X", (uint16_t)(chipId >> 32), (uint32_t)chipId);
    return String(chipIdChar);
}

String HONEYLemon::getMAC() {
	uint8_t mac[6];
	esp_efuse_mac_get_default(mac);
    char macChar[20];
	sprintf(macChar, "%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return String(macChar);
}

#endif