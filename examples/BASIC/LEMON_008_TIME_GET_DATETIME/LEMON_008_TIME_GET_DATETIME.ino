/*
    Basic : การเขียนโปรแกรมกับอ่านค่าวันที่จากอินเตอร์เน็ตบนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/basic-008-time-get-datetime-วันเวลา/
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
    /*
        getDateTime()   // อ่านค่า ปี-เดือน-วัน และ ชั่วโมง:นาที:วินาที Year-Month-Day T Hour:Minute:Second (String)
    */
    Serial.println( lemon.getDateTime() );  // อ่านค่าพร้อมแสดงผลวันเวลา Year-Month-Day T Hour:Minute:Second
    delay(1000);    // รอ 1000 มิลลิวินาที (1 วินาที)
}