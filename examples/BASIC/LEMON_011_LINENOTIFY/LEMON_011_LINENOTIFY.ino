/*
    Basic : การเขียนโปรแกรมกับการแจ้งเตือนผ่าน Line Notify บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/blogs/basic/basic-011-line-notify
*/
#include <HONEYLemon.h>

#define WIFI_SSID  "WiFi_Name"      // ตั้งค่าชื่อ WiFi
#define WIFI_PASS  "WiFi_Password"  // ตั้งค่ารหัสผ่าน WiFi
#define LINE_TOKEN "LINE_Token"     // ตั้งค่า Token ของ Line Notify

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    // เรียกการใช้งานการตั้งค่า WiFi
    lemon.setupWiFi(WIFI_SSID, WIFI_PASS);

    /*
        lineNotify(
            LINE_TOKEN,         // ตั้งค่า Token ของ Line Notify
            "Hello HONEYLemon"  // ข้อความที่ต้องการแสดงผล
        )
    */
    lemon.lineNotify(LINE_TOKEN,"Hello HONEYLemon");    // แจ้งเตือนผ่าน Line Notify ด้วยข้อความ "Hello HONEYLemon"
}

void loop()
{
}
