#ifndef __HONEYLemon_LED_RGB_CPP__
#define __HONEYLemon_LED_RGB_CPP__

#include "HONEYLemon.h"

/* LED RGB Function */
void HONEYLemon::setColorLED(uint8_t i,uint8_t r,uint8_t g,uint8_t b){

    if(r<=0)r=0; else if(r>255)r=255;
    if(g<=0)g=0; else if(g>255)g=255;
    if(b<=0)b=0; else if(b>255)b=255;
    if(i<=0){
        for(uint8_t i=0;i<6;i++)
            _leds[i]=CRGB(r,g,b); // ALL LED
    }else{
        _leds[i-1]=CRGB(r,g,b); // LED 1 - 6
    }
    LED.show();
}
void HONEYLemon::setBrightnessLED(uint8_t lv){
    if(lv <= 0) lv = 0;
    else if(lv > 255)lv = 255;
    LED.setBrightness(lv);
}

#endif