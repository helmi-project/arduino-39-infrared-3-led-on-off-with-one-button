/*
   TUTORIAL IR REMOTE RECEIVER PADA ARDUINO
   DAN ON OFF LED DENGAN 1 TOMBOL
   
   D4 -> Led Merah
   D6 -> Led Biru
   

*/

#include "EcadioIRremote.h"

#define RECV_PIN 2//the SIG pin of Infrared Receiver is connected with D2 of OPEN-SMART UNO R3
#define biru 6 
#define merah 4 

IRrecv IR(RECV_PIN);
int statusLed = LOW;

void setup()
{
  Serial.begin(115200);
  IR.enableIRIn(); // memulai receiver
  pinMode(biru, OUTPUT);
  pinMode(merah, OUTPUT);

}

void loop()
{
  if (IR.decode()) {//kalau ada kode yang valid

    if (IR.isReleased()) 
    {
      digitalWrite(merah, HIGH);
      Serial.print("key code is ");
      Serial.println(IR.keycode, DEC);
      Serial.println("*************");
      
    }
    digitalWrite(merah, LOW);
    if(IR.keycode==28){
      statusLed = !statusLed; //kebalikan nya
      
    }
    digitalWrite(biru,statusLed);
    IR.resume(); //lanjutkan menerima sinyal IR lagi
  }
}
