/*
    Basic : การเขียนโปรแกรมเพื่อดู debug บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/basic-001-debug-%e0%b8%94%e0%b8%b5%e0%b8%9a%e0%b8%b1%e0%b8%81/
*/
#include <HONEYLemon.h>

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial
}

void loop()
{
}