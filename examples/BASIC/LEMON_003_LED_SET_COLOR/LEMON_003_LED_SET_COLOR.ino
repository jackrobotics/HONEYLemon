/*
    Basic : การเขียนโปรแกรมกับการใช้งานไฟ LED RGB บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/blogs/basic/basic-003-set-led-color-rgb-rgb-led
*/
#include <HONEYLemon.h>

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    lemon.setBrightnessLED(50); // สำหรับปรับความสว่าง 0-255
}

void loop()
{
    /*
        setColorLED(
            0,      // ใส่ 0 สำหรับทุกหลอด หรือระบุ 1,2,3,4,5,6 สำหรับสั่งงานเฉพาะหลอดนั้นๆ
            255,    // สำหรับตั้งค่าแสงสีแดง 0-255
            255,    // สำหรับตั้งค่าแสงสีเขียว 0-255
            255     // สำหรับตั้งค่าแสงสีน้ำเงิน 0-255
        );
    */
    lemon.setColorLED(0,255,0,0);   // สั่งให้ทุกหลอดแสดงสีแดง
    delay(1000);    // รอ 1000 มิลลิวินาที (1 วินาที)

    lemon.setColorLED(0,0,255,0);   //สั่งให้ทุกหลอดแสดงสีเขียว
    delay(1000);    // รอ 1000 มิลลิวินาที (1 วินาที)

    lemon.setColorLED(0,0,0,255);   //สั่งให้ทุกหลอดแสดงสีน้ำเงิน
    delay(1000);    // รอ 1000 มิลลิวินาที (1 วินาที)
}
