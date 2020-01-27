/*
    Basic : การเขียนโปรแกรมกับอ่านค่าวันเวลาจากอินเตอร์เน็ตบนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/basic-009-time-get-date-วัน/
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
        getDate()       // อ่านค่าวันที่ ปี-เดือน-วัน (Year-Month-Day) (String)
        getDate_Day()   // อ่านค่าวันที่ Day 1-31    (int)
        getDate_Mouth() // อ่านค่าเดือน Mouth 1-12 (int)
        getDate_Year()  // อ่านค่าปี (ค.ศ.)        (int)
    */

    // กำหนดตัวแปรสำหรับเก็บข้อมูลชื่อวัน
    String textDays[] ={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    Serial.print( textDays[lemon.getDate_DayOfWeek()] );  // แสดงผลชื่อวัน

    Serial.println( lemon.getDate() );  // แสดงผล ปี-เดือน-วัน Year-Month-Day

    //Serial.println( lemon.getDate_Day() );    // แสดงผลวันที่
    //Serial.println( lemon.getDate_Month() );  // แสดงผลเดือนที่
    //Serial.println( lemon.getDate_Year() );   // แสดงผลปีที่ (ค.ศ.)

    delay(1000);    // รอ 1000 มิลลิวินาที (1 วินาที)
}