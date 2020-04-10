/*
    Advanced : การเขียนโปรแกรมอ่านค่า Power Meter (SDM120CT-MV) ผ่าน Modbus Protocol บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
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

float convertIEEE754(uint16_t a,uint16_t b){
    uint32_t x = (a<<16)|b;
    float y = *(float*)&x;
    return y;
}

void loop()
{
    if( millis()-lastUpdate > 1000 ){   // ทำงานทุกๆ 1000 มิลลิวินาที ( 1 วินาที )
        lastUpdate = millis();          // Update เวลาล่าสุดเก็บไว้ใน lastUpdate

        // Voltage
        int voltage_high = lemon.readIregModbusRTU(5,0);   // อ่านค่าจาก id: 5, address: 0
        int voltage_low = lemon.readIregModbusRTU(5,1);   // อ่านค่าจาก id: 5, address: 1
        float voltage = convertIEEE754(voltage_high,voltage_low);  // แปลงค่าเป็น float
        
        // Current
        int current_high = lemon.readIregModbusRTU(5,6);   // อ่านค่าจาก id: 5, address: 6
        int current_low = lemon.readIregModbusRTU(5,7);   // อ่านค่าจาก id: 5, address: 7
        float current = convertIEEE754(current_high,current_low);  // แปลงค่าเป็น float
        
        // Active Power
        int active_power_high = lemon.readIregModbusRTU(5,12);   // อ่านค่าจาก id: 5, address: 12
        int active_power_low = lemon.readIregModbusRTU(5,13);   // อ่านค่าจาก id: 5, address: 13
        float active_power = convertIEEE754(active_power_high,active_power_low);  // แปลงค่าเป็น float
        
        // Import Active Energy
        int kwh_high = lemon.readIregModbusRTU(5,72);   // อ่านค่าจาก id: 5, address: 72
        int kwh_low = lemon.readIregModbusRTU(5,73);   // อ่านค่าจาก id: 5, address: 73
        float kwh = convertIEEE754(kwh_high,kwh_low);  // แปลงค่าเป็น float
        
        // Power Factor
        int pf_high = lemon.readIregModbusRTU(5,30);   // อ่านค่าจาก id: 5, address: 30
        int pf_low = lemon.readIregModbusRTU(5,31);   // อ่านค่าจาก id: 5, address: 31
        float pf = convertIEEE754(pf_high,pf_low);  // แปลงค่าเป็น float
        
        // Frequency
        int freq_high = lemon.readIregModbusRTU(5,70);   // อ่านค่าจาก id: 5, address: 70
        int freq_low = lemon.readIregModbusRTU(5,71);   // อ่านค่าจาก id: 5, address: 71
        float freq = convertIEEE754(freq_high,freq_low);  // แปลงค่าเป็น float

        Serial.println("Voltage: "+String(voltage)+" ,Current: "+String(current)+" ,Active Power: "+String(active_power)+" ,kWh: "+String(kwh)+" ,PF: "+String(pf)+" ,Freq: "+String(freq));  // แสดงผลผ่านหน้าจอมอนิเตอร์
    }
}