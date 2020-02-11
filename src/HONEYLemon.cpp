#ifndef __HONEYLemon_CPP__
#define __HONEYLemon_CPP__

#include "HONEYLemon.h"

/* Setup Function */
HONEYLemon::HONEYLemon(){
    this->modeDebug=false;
    this->modeModbusRTU=false;
    this->modeMicroSDCard=false;

    /* Setup for Button Function */
    this->_user_btn_on_click_cb = [](void) -> void { };
    this->_user_btn_on_long_click_cb = [](void) -> void { };
    this->_user_btn_on_double_click_cb = [](void) -> void { };
}

void HONEYLemon::begin(){
    RS485.begin(9600, SERIAL_8N1, 16, 17);

    LED.addLeds<NEOPIXEL, PIN_LED>(_leds, 6);
    this->setColorLED(0,0,0,0);
    
    if(!SD.begin(PIN_SDCARD)){
        this->modeMicroSDCard=false;
        DEBUG_PRINTLN("Micro SD Card Mount Failed");
    }else{
        this->modeMicroSDCard=true;
        if(this->HONEYLemonUpdateFirmwareWithSDCard())ESP.restart();
    }

    xTaskCreate([](void*) {
        while ( true ) {
            lemon.Task_Loop();
            vTaskDelay(5);
        }
    }, "task_loop", 4096, NULL, 1, NULL);
}

/* Task Loop */
void HONEYLemon::Task_Loop(){
    this->USER_BTN.update();
    if( this->USER_BTN.isPressed() )this->_user_btn_on_click_cb();
    if( this->USER_BTN.isLongPressed())this->_user_btn_on_long_click_cb();
    if( this->USER_BTN.isDoubleClick())this->_user_btn_on_double_click_cb();

    if(this->modeModbusRTU){
        this->_ModbusRTU.task();
    }

    static unsigned long lastWiFiCheck = millis();
    if(this->modeWiFi && millis()-lastWiFiCheck > 1000){
        lastWiFiCheck = millis();
        if(_WiFi.run() != WL_CONNECTED){
            DEBUG_PRINTLN("Reconnect WiFi...");
        }
    }
    static unsigned long lastUpdateNTP = 0;
    if(this->modeWiFi && millis()-lastUpdateNTP > 60000){
        lastUpdateNTP = millis();
        if(_WiFi.run() == WL_CONNECTED){
            DEBUG_PRINTLN("Update Time Server");
            configTime(25200, 0, "ntp.ku.ac.th", "pool.ntp.org", "time.nist.gov");
        }
    }

    static unsigned long lastUpdateTimeVariable = 0;
    if(this->modeWiFi && millis()-lastUpdateTimeVariable > 500){
        lastUpdateTimeVariable = millis();
        getLocalTime(&timeInfo);
    }
}

HONEYLemon lemon;
#endif