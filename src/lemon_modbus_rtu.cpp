#ifndef __HONEYLemon_MODBUS_RTU_CPP__
#define __HONEYLemon_MODBUS_RTU_CPP__

#include "HONEYLemon.h"

/* RS485 Communication */
    /* Modbus RTU */
void HONEYLemon::setModeModbusRTU(bool _modeModbusRTU){
    if(_modeModbusRTU){
        this->_ModbusRTU.begin(&RS485);
        this->_ModbusRTU.master();
    }
    this->modeModbusRTU=_modeModbusRTU;
}
bool HONEYLemon::checkTimeoutModbusRTU(){
    unsigned long _timecheck = millis();
    while(!(RS485.available() > 0) && !(millis()-_timecheck > MODBUSRTU_TIMEOUT));
    if(millis()-_timecheck > MODBUSRTU_TIMEOUT){
        DEBUG_PRINTLN("RS485 Modbus RTU Timeout!!!");
        delay(50);
        return false;
    }else{
        delay(50);
        return true;
    }
}
uint16_t HONEYLemon::readIregModbusRTU(uint16_t id,uint16_t addr){
    uint16_t tmp[]={0};
    if(!this->_ModbusRTU.slave() && this->modeModbusRTU){
        this->_ModbusRTU.readIreg(id,addr,tmp,1);
        this->checkTimeoutModbusRTU();
    }
    return tmp[0];
}
bool HONEYLemon::readIstsModbusRTU(uint16_t id,uint16_t addr){
    bool tmp[]={0};
    if(!this->_ModbusRTU.slave() && this->modeModbusRTU){
        this->_ModbusRTU.readIsts(id,addr,tmp,1);
        this->checkTimeoutModbusRTU();
    }
    return tmp[0];
}
uint16_t HONEYLemon::readHregModbusRTU(uint16_t id,uint16_t addr){
    uint16_t tmp[]={0};
    if(!this->_ModbusRTU.slave() && this->modeModbusRTU){
        this->_ModbusRTU.readHreg(id,addr,tmp,1);
        this->checkTimeoutModbusRTU();
    }
    return tmp[0];
}
bool HONEYLemon::readCoilModbusRTU(uint16_t id,uint16_t addr){
    bool tmp[]={0};
    if(!this->_ModbusRTU.slave() && this->modeModbusRTU){
        this->_ModbusRTU.readCoil(id,addr,tmp,1);
        this->checkTimeoutModbusRTU();
    }
    return tmp[0];
}
bool HONEYLemon::writeHregModbusRTU(uint16_t id,uint16_t addr, uint16_t value){
    bool tmp=false;
    if(!this->_ModbusRTU.slave() && this->modeModbusRTU){		
        this->_ModbusRTU.writeHreg(id,addr,value);
        tmp=this->checkTimeoutModbusRTU();
    }
    return tmp;
}
bool HONEYLemon::writeCoilModbusRTU(uint16_t id,uint16_t addr, bool value){
    bool tmp=false;
    if(!this->_ModbusRTU.slave() && this->modeModbusRTU){
        this->_ModbusRTU.writeCoil(id,addr,value);
        tmp=this->checkTimeoutModbusRTU();
    }
    return tmp;
}

float HONEYLemon::convertIEEE754(uint32_t a,uint32_t b){
    uint32_t x = (a<<16)|b;
    float y = *(float*)&x;
    return y;
}
float HONEYLemon::convertIEEE754(uint32_t x){
    float y = *(float*)&x;
    return y;
}
#endif