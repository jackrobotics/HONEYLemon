/*
    Basic : การเขียนโปรแกรมกับอ่านค่าเวลาจากอินเตอร์เน็ตบนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/basic-010-time-get-time-เวลา/
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
        getTime()           // อ่านค่าเวลา ชั่วโมง:นาที:วินาที Hour:Minute:Second (String)
        getTime_Hour()      // อ่านค่าชั่วโมง Hour   0-23  (int)
        getTime_Minute()    // อ่านค่านาที Minute 0-60  (int)
        getTime_Second()    // อ่านค่าวินาที Second 0-60  (int)
    */
   
    Serial.println( lemon.getTime() );  // แสดงผลเวลา Hour:Minute:Second

    // Serial.println( lemon.getTime_Hour() );  // แสดงผลชั่วโมง
    //Serial.println( lemon.getTime_Minute() ); // แสดงผลนาที
    //Serial.println( lemon.getTime_Second() ); // แสดงผลวินาที

    delay(1000);    // รอ 1000 มิลลิวินาที (1 วินาที)
}