/* Библиотеки */
#include <Wire.h>
#include <RTClib.h>
#include "GyverNTC.h"

/* Классы системы */
#include "SystemControl.h" 


RTC_DS3231 rtc; // Инициализация объекта класса для RTC модуля
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

  /* Установка часов */

  if (!rtc.begin()) {
    Serial.println("Ошибка: модуль RTC не найден!");
    while (1) 
    {
      systemControl.setSystemStatus(SystemStatus::ERROR);
      systemControl.systemStatusCheck();
    };  // Остановка выполнения при ошибке
  }

  // Если часы остановлены (например, села батарейка)
  if (rtc.lostPower()) {
    Serial.println("Питание RTC потеряно, устанавливаем время компиляции скетча");
    // Устанавливаем время согласно моменту компиляции скетча
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // Альтернатива: установка конкретных даты и времени:
    // rtc.adjust(DateTime(2026, 5, 17, 14, 30, 0));
  }
}


void loop() {

}
