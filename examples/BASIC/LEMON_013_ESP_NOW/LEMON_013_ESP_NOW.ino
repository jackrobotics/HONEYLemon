/*
    Basic : การเขียนโปรแกรมสื่อสารไร้สายด้วย ESP-NOW
    อ่านข้อมูลเพิ่มเติม : https://lemon.honey.co.th/blogs/basic/basic-013-esp-now
*/
#include <HONEYLemon.h>

// ฟังก์ชั่นสำหรับการรับข้อมูลสำหรับ ESP-NOW
void espnowRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
    char macStr[22];
    snprintf(macStr, sizeof(macStr), "[%02X:%02X:%02X:%02X:%02X:%02X]: ", mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);

    Serial.print(macStr);
    Serial.write(data, data_len);
    Serial.println();
}

void setup()
{
    lemon.begin();          // เรียกใช้งานฟังก์ชั่นเริ่มต้นของบอร์ด HONEYLemon

    Serial.begin(115200);   // เรียกใช้งาน Serial
    lemon.debug(Serial);    // ขอดู debug ของบอร์ด HONEYLemon ผ่าน Serial

    Serial.println("My MAC Address : "+lemon.getMAC()); // แสดง MAC Address ของตัวเอง

    lemon.setupESPNOW();    // เรียกใช้งาน ESP-NOW
    esp_now_register_recv_cb(espnowRecv);   // เมื่อมีข้อมูลส่งกลับมาจะให้เรียกฟังก์ชั่น espnowRecv
}

void loop()
{
    // lemon.espnow_send("FF:FF:FF:FF:FF:FF","Hello World!"));  // ส่งคำว่า Hello World! ไปหาอุปกรณ์ MAC Addess ปลายทางผ่าน ESP-NOW
    lemon.espnow_broadcast("Hello World!");                     // ส่งคำว่า Hello World! ไปหาอุปกรณ์ทุกตัวผ่าน ESP-NOW
    delay(1000);    // รอ 1000 มิลลิวินาที ( 1 วินาที )
}
