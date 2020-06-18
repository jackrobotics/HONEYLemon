/*
    Basic : การเขียนโปรแกรมกับการใช้งานเสียงดนตรีเพลง Jingle bells บนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/blogs/basic/basic-005-sound-play-jingle-bells
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
    // สร้างอาเรย์สำหรับเก็บข้อมูลตัวโน๊ต
    int notes[]={
        659, 659, 659, -1,  659, 659, 659, -1,  659, 784, 523,
        587, 659, -1,  698, 698, -1,  698, 698, -1,  698, 659,
        659, 659, 659, -1,  659, 587, 587, 659, 587, 784
    };
    
    // วนอ่านข้อมูลตัวโน๊ตแต่ละตัวในอาเรย์ notes[]
    for(int i=0;i<(sizeof(notes)/sizeof(int *));i++){
        lemon.tone(notes[i],400);   // สั่งให้เล่นตัวโน๊ต
    }

    lemon.noTone();     // สั่งให้หยุเล่นเสียง
    delay(1000);        // รอ 10000 มิลลิวินาที (10 วินาที)
}
