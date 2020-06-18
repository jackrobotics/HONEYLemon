/*
    Basic : การเขียนโปรแกรมควบคุม Servo บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/blogs/basic/basic-012-servo-sweep
*/
#include <HONEYLemon.h>

Servo myservo;      // สร้าง object สำหรับการควบคุม servo
int servoPin = 4;   //สร้างตัวแปรควบคุม Servo ( ขาที่ใช้งานได้ 4,12,14,15,18,19,21,22,23,25,26 )

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    myservo.setPeriodHertz(50);     // ตั้งค่าความถี่มาตรฐาน 50 Hz
    myservo.attach(servoPin);       // กำหนดคาบเวลา min/max ที่จะใช้ควบคุม Servo
}

void loop()
{
    for (int pos = 0; pos <= 180; pos++) {  // ทำการกำหนดมุมเริ่มต้นเป็น 0 และทำงานซ้ำไปจนถึงมุม 180 โดยที่แต่ละรอบมีการเปลี่ยนแปลงมุม +1 อาศา
        myservo.write(pos);     // สั่งให้ Servo หมุนไปที่ตำแหน่ง pos (position)
        delay(15);              // รอ 15 มิลลิวินาที
	}
    for (int pos = 180; pos >= 0; pos--) {  // ทำการกำหนดมุมเริ่มต้นเป็น 180 และทำงานซ้ำไปจนถึงมุม 0 โดยที่แต่ละรอบมีการเปลี่ยนแปลงมุม -1 อาศา
        myservo.write(pos);     // สั่งให้ Servo หมุนไปที่ตำแหน่ง pos (position)
        delay(15);              // รอ 15 มิลลิวินาที
	}
}
