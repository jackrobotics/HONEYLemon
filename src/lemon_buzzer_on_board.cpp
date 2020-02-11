#ifndef __HONEYLemon_BUZZER_CPP__
#define __HONEYLemon_BUZZER_CPP__

#include "HONEYLemon.h"

/* Buzzer / Sound Function */
void HONEYLemon::sound(unsigned long freq,unsigned long duration){
    ledcAttachPin(PIN_BUZZER, 0);
    ledcWriteTone(0, freq);
    if(duration != 0){
        delay(duration);
        this->noTone();
    }
}

#endif