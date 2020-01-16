/*
    Basic : การเขียนโปรแกรมเพื่อดู debug บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
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