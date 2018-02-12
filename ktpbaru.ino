#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#define pinSS 10
#define pinReset 9

MFRC522 RFID(pinSS, pinReset);
String ID;
void setup(){
  Serial.begin(9600);
  SPI.begin();
  RFID.PCD_Init();
  Serial.println("RFID Reader");
}
void loop(){
  if ( ! RFID.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! RFID.PICC_ReadCardSerial()) {
    return;
  }
  
  Serial.print("ID :");
  String ID = "";
  byte letter;
  for (byte i = 0; i < RFID.uid.size; i++) {
    ID.concat(String(RFID.uid.uidByte[i], HEX));
  }
  Serial.print(ID);
  Serial.println();
  delay(2500);
}

