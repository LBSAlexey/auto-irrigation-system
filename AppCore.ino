#include "SystemControl.h"

SystemControl systemControl; // Инициализация объекта класса

void setup() {
  Serial.begin(115200);

  /* Распиновка */ 
  // Дискретные входы:
  pinMode(static_cast<uint8_t>(DigitalPinsInput::ButtonStart), INPUT_PULLUP);
  pinMode(static_cast<uint8_t>(DigitalPinsInput::ButtonStop), INPUT_PULLUP); 
  pinMode(static_cast<uint8_t>(DigitalPinsInput::UpperLevel), INPUT);
  pinMode(static_cast<uint8_t>(DigitalPinsInput::LowerLevel), INPUT);
  // Дискретные выходы: 
  pinMode(static_cast<uint8_t>(DigitalPinsOutput::LedStart), OUTPUT);
  pinMode(static_cast<uint8_t>(DigitalPinsOutput::LedStop), OUTPUT);
  pinMode(static_cast<uint8_t>(DigitalPinsOutput::RelayPit), OUTPUT);
  pinMode(static_cast<uint8_t>(DigitalPinsOutput::RelayBarrel), OUTPUT);

  
}


void loop() {
  // put your main code here, to run repeatedly:

}
