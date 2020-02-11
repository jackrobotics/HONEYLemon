#ifndef __HONEYLemon_WiFi_Function_CPP__
#define __HONEYLemon_WiFi_Function_CPP__

#include "HONEYLemon.h"

/* WiFi Function */
bool HONEYLemon::setupWiFi(String ssid,String pass){
    DEBUG_PRINT("Setup WiFi ssid: "+ssid+" pass: "+pass+"\n");
    WiFi.mode(WIFI_STA);
    DEBUG_PRINT("Connecting WiFi.");
    this->_WiFi.addAP(ssid.c_str(), pass.c_str());
    unsigned long connect_time = millis();
    while( (millis() - connect_time < 30000) && _WiFi.run() != WL_CONNECTED ){
        DEBUG_PRINT(".",false);
        delay(100);
    }
    DEBUG_PRINT("\n",false);
    if(_WiFi.run() == WL_CONNECTED) {
        DEBUG_PRINTLN("WiFi Connected IP Address: "+WiFi.localIP().toString());
        DEBUG_PRINT("Waiting for NTP time sync: ");
        configTime(25200, 0, "ntp.ku.ac.th", "pool.ntp.org", "time.nist.gov");
        getLocalTime(&timeInfo);
        DEBUG_PRINT(asctime(&timeInfo),false);
        this->modeWiFi=true;
        return true;
    }else{
        DEBUG_PRINTLN("Can't Connect to WiFi");
        this->modeWiFi=true;
        return false;
    }
}
bool HONEYLemon::lineNotify(String token,String msg){
    bool success = false;
    DEBUG_PRINTLN("Line Notify : "+msg);
    WiFiClientSecure *_clientSecure = new WiFiClientSecure;
    if(_clientSecure) {
        HTTPClient https;
        if (https.begin(*_clientSecure, "https://notify-api.line.me/api/notify")) {
            https.addHeader("Authorization","Bearer "+token);
            https.addHeader("Content-Type", "application/x-www-form-urlencoded");
            int httpCode = https.POST("message="+msg);
            if (httpCode == HTTP_CODE_OK)success=true;
            https.end();
        }
        delete _clientSecure;
    }
    return success;
}


#endif