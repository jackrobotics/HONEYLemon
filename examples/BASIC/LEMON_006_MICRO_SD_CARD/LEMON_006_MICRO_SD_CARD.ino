/*
    Basic : การเขียนโปรแกรมกับการใช้งานไมโครเอสดีการ์ดบนบอร์ดไมโครคอนโทรลเลอร์ HONEYLemon
*/
#include <HONEYLemon.h>

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    /*
        Micro SD Card Function
        
        createFile(__Filename__)                // สำหรับสร้างไฟล์บนไมโครเอสดีการ์ด
        
        writeFile(__Filename__, __Text__)       // สำหรับเขียนตัวอักษรลงบนไฟล์ในไมโครเอสดีการ์ด
        writeFileln(__Filename__, __Text__)     // สำหรับเขียนตัวอักษรลงบนไฟล์ในไมโครเอสดีการ์ด พร้อมเว้นบรรทัด
        
        readFile(__Filename__)                  // สำหรับอ่านไฟล์ โดยจะคืนค่าเป็นสตริง (String)
        removeFile(__Filename__)                // สำหรับลบไฟล์
        
        renameFile(old___Filename__,new___Filename__)   // สำหรับเปลี่ยนชื่อไฟล์
    */

   lemon.createFile("text.txt");                        // สร้างไฟล์ชื่อว่า text.txt
   lemon.writeFile("text.txt","Hello HONEYLemon\n");    // เขียนข้อความว่า "Hello HONEYLemon" ลงในไฟล์ text.txt
   
   Serial.println( lemon.readFile("text.txt") );        // อ่านไฟล์ text.txt (String) แล้วแสดงผล

   lemon.renameFile("text.txt","text.txt.backup");      // เปลี่ยนชื่อไฟล์ text.txt เป็น text.txt.backup
   lemon.removeFile("text.txt.backup");                 // ลบไฟล์ text.txt.backup
}

void loop()
{
}