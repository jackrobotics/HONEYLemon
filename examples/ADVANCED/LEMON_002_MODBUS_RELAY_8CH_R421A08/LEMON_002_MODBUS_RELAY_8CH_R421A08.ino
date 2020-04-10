/*
    Advanced : การเขียนโปรแกรมควบคุม Relay 8CH (R421A08) ผ่าน Modbus Protocol บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
*/
#include <HONEYLemon.h>

#define RELAY_ON  0x0100
#define RELAY_OFF 0x0200

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    lemon.setModeModbusRTU();   // เปิดโหมดการใช้งาน Modbus RTU
}

void loop()
{
    for(int i=1;i<=8;i++){
      lemon.writeHregModbusRTU(1,i,RELAY_ON);   // สั่งให้ relay on ตั้งแต่ตัวที่ 1-8 ( Device ID : 1 )
      delay(100);
    }
    for(int i=1;i<=8;i++){
      lemon.writeHregModbusRTU(1,i,RELAY_OFF);  // สั่งให้ relay off ตั้งแต่ตัวที่ 1-8 ( Device ID : 1 )
      delay(100);
    }
}