/*
    Basic : การเขียนโปรแกรมกับการใช้งานปุ่มกดบนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
*/
#include <HONEYLemon.h>

void BTN_Click(){       // ฟังก์ชั่นสำหรับการกดปุ่มครั้งเดียว
    Serial.println("Button Click!");        // แสดงผลที่หน้าจอมอนิเตอร์
}
void BTN_LongClick(){   // ฟังก์ชั่นสำหรับการกดปุ่มค้าง
    Serial.println("Button Long Click!");   // แสดงผลที่หน้าจอมอนิเตอร์
}
void BTN_DoubleClick(){ // ฟังก์ชั่นสำหรับการกดปุ่มสองครั้ง
    Serial.println("Button Double Click!"); // แสดงผลที่หน้าจอมอนิเตอร์
}

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    /*
        Function Event Callback

        onClick( __function__ );        // สำหรับกดปุ่มครั้งเดียว
        onLongClick( __function__ );    // สำหรับกดปุ่มค้าง
        onDoubleClick( __function__ );  // สำหรับกดปุ่มสองครั้ง
    */

    lemon.onClick(BTN_Click);               // หากกดปุ่มครั้งเดียวให้เรียกใช้งานฟังก์ชั่น BTN_Click()
    lemon.onLongClick(BTN_LongClick);       // หากกดปุ่มค้างให้เรียกใช้งานฟังก์ชั่น BTN_LongClick()
    lemon.onDoubleClick(BTN_DoubleClick);   // หากกดปุ่มสองครั้งให้เรียกใช้งานฟังก์ชั่น BTN_DoubleClick()
}

void loop()
{
}