#ifndef __HONEYLemon_H__
#define __HONEYLemon_H__

#include "Arduino.h"

#include "FS.h"
#include "SD.h"
#include "SPI.h"
// #include "lib/ArduinoJson/ArduinoJson.h"
// #include "lib/PubSubClient/PubSubClient.h"
#include <algorithm>

#include "lib/FastLED/FastLED.h"
#include "lib/TridentTD_EasyButton/TridentTD_EasyButton.h"
#include "lib/Modbus/ModbusRTU.h"
#include "lib/ESP32Servo/ESP32Servo.h"

#if defined(ESP32)
    #include <WiFi.h>
    #include <WiFiMulti.h>
    #include <HTTPClient.h>
    #include <WiFiClientSecure.h>
    #include <Update.h>
    #include <esp_now.h>
#endif

#define PIN_USERBTN 0
#define PIN_LED 2
#define PIN_SDCARD 13
#define PIN_BUZZER 27

#define RS485 Serial2

#define Version "0.1.2"

typedef void (*voidCb_t)(void);

class HONEYLemon
{
    private:
        /* For MicroSDCard */
        bool modeMicroSDCard;

        /* For Debug */
        Stream* SERIAL_DEBUG;
        bool modeDebug;
        void DEBUG_PRINT(String,bool header=true);
        void DEBUG_PRINTLN(String _msg="",bool header=true){DEBUG_PRINT(_msg+"\n",header);};

        /* For User BTN */
        voidCb_t _user_btn_on_click_cb;
        voidCb_t _user_btn_on_long_click_cb;
        voidCb_t _user_btn_on_double_click_cb;
        TridentTD_EasyButton USER_BTN;

        /* For Modbus-RTU */
        bool modeModbusRTU;

        /* For WiFi */
        WiFiMulti _WiFi;
        bool modeWiFi;

        /* For Time with NTC*/
        struct tm timeInfo;

        /* For ESP-NOW */
        esp_now_peer_info_t esp_now_slave;
        uint8_t esp_now_broadcastAddr[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    public:
        /* Setup Function */
        HONEYLemon();
        void begin();

        /* Debug Function*/
        void debug(Stream &);

        /* WiFi Function File : lemon_wifi_function.cpp */
        bool setupWiFi(String,String);
        bool lineNotify(String,String);

        /* NTP / Time Function */
        int getTime_Second(){return timeInfo.tm_sec;}
        int getTime_Minute(){return timeInfo.tm_min;}
        int getTime_Hour(){return timeInfo.tm_hour;}
        int getDate_Day(){return timeInfo.tm_mday;}
        int getDate_Month(){return (timeInfo.tm_mon+1);}
        int getDate_Year(){return (timeInfo.tm_year+1900);}
        int getDate_DayOfWeek(){return timeInfo.tm_wday;}
        String getDate(){return ((String)(getDate_Year()))+"-"+((getDate_Month()<10)?"0"+(String)getDate_Month():(String)getDate_Month())+"-"+((getDate_Day()<10)?"0"+(String)getDate_Day():(String)getDate_Day());}
        String getTime(){return ((getTime_Hour()<10)?"0"+(String)getTime_Hour():(String)getTime_Hour())+":"+((getTime_Minute()<10)?"0"+(String)getTime_Minute():(String)getTime_Minute())+":"+((getTime_Second()<10)?"0"+(String)getTime_Second():(String)getTime_Second());}
        String getDateTime(){return getDate()+"T"+getTime();}

        /* Button Function File : lemon_button_on_board.cpp*/
        void onClick(voidCb_t cb);
        void onLongClick(voidCb_t cb);
        void onDoubleClick(voidCb_t cb);

        /* LED RGB Function File : lemon_led_rgb_on_board.cpp */
        CRGB _leds[6];
        CFastLED LED;
        void setColorLED(uint8_t,uint8_t,uint8_t,uint8_t);
        void setBrightnessLED(uint8_t);
        
        /* Buzzer / Sound Function File : lemon_buzzer_on_board.cpp */
        void sound(unsigned long,unsigned long duration=0);
        void tone(unsigned long freq,unsigned long duration=0){sound(freq,duration);}
        void noTone(){ledcDetachPin(PIN_BUZZER);ledcWrite(0, 0);}

        /* Micro SD Card File : lemon_sd_card_on_board.cpp */
        bool createFile(String filename);
        bool writeFile(String filename, String text);
        bool writeFileln(String filename, String text);
        String readFile(String filename);
        bool renameFile(String old_filename,String new_filename);
        bool removeFile(String filename);
        bool HONEYLemonUpdateFirmwareWithSDCard(String filename="HONEYLemon.bin");
        
        /* RS485 Communication File : lemon_modbus_rtu.cpp */
            /* Modbus RTU */
        ModbusRTU _ModbusRTU;
        bool checkTimeoutModbusRTU();
        void setModeModbusRTU(bool _modeRTU=true);
        uint16_t readIregModbusRTU(uint16_t id,uint16_t addr);
        bool readIstsModbusRTU(uint16_t id,uint16_t addr);
        uint16_t readHregModbusRTU(uint16_t id,uint16_t addr);
        bool readCoilModbusRTU(uint16_t id,uint16_t addr);
        bool writeHregModbusRTU(uint16_t id,uint16_t addr, uint16_t value);
        bool writeCoilModbusRTU(uint16_t id,uint16_t addr, bool value);

        /* File : lemon_esp_now.cpp */
        void setupESPNOW();
        bool espnow_send(char *,char *);
        bool espnow_send(String,String);
        bool espnow_broadcast(char *);
        bool espnow_broadcast(String);
        String espnow_mac2str(uint8_t *);

        /* Task Loop */
        void Task_Loop();

        /* File : lemon_utility.cpp */
        String getVersion();
        String getChipId();
        String getMAC();
};

extern HONEYLemon lemon;
#endif