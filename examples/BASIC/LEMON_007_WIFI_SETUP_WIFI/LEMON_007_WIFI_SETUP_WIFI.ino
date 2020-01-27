/*
    Basic : การเขียนโปรแกรมกับการเชื่อมต่ออินเตอร์เน็ตผ่าน WiFi บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/basic-007-wifi-setup-wifi-ต่อเน็ต/
*/
#include <HONEYLemon.h>

#define WIFI_SSID  "WiFi_Name"      // ตั้งค่าชื่อ WiFi
#define WIFI_PASS  "WiFi_Password"  // ตั้งค่ารหัสผ่าน WiFi

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    // เรียกการใช้งานการตั้งค่า WiFi
    lemon.setupWiFi(WIFI_SSID, WIFI_PASS);
}

void loop()
{
}