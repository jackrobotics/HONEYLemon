/*
    Advanced : การเขียนโปรแกรมอ่านค่า Sensor Temp & Humi (XY-MD02) ผ่าน Modbus Protocol บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
*/
#include <HONEYLemon.h>

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    lemon.setModeModbusRTU();   // เปิดโหมดการใช้งาน Modbus RTU
}

unsigned long lastUpdate = 0;   // สร้างตัวแปรสำหรับการเช็คเวลาล่าสุดในการอ่านค่า Modbus

void loop()
{
    if( millis()-lastUpdate > 1000 ){   // ทำงานทุกๆ 1000 มิลลิวินาที ( 1 วินาที )
        lastUpdate = millis();          // Update เวลาล่าสุดเก็บไว้ใน lastUpdate

        float humi = lemon.readIregModbusRTU(1,2)/10.0;   // อ่านค่าจาก id: 1, address: 2 เก็บไว้ในตัวแปร humi
        float temp = lemon.readIregModbusRTU(1,1)/10.0;   // อ่านค่าจาก id: 1, address: 1 เก็บไว้ในตัวแปร temp

        Serial.println("Temp: "+String(temp)+" ,Humi: "+String(humi));  // แสดงผลผ่านหน้าจอมอนิเตอร์
    }
}