#ifndef PINS_H
#define PINS_H
#include <Arduino.h>

enum class DigitalPinsInput // Дискретные входы
{
  ButtonStart = 11, // Кнопка запуска системы
  ButtonStop = 10, // Кнопка остановки системы
  UpperLevel = 7,   // Датчик уровня жидксоти - верхний уровень
  LowerLevel = 6    // Датчик уровня жидксоти - нижний уровень
};


enum class DigitalPinsOutput // Дискретные выходы
{
  LedStart = 9,   // Светодиод зелёный - система запущена
  LedStop = 8,    // Светодиод красный - система остановлена
  RelayPit = 4,   // Реле на насос колодца
  RelayBarrel = 5 // Реле на насос бочки
};

enum class AnalogPins // Аналоговые пины
{
  NTCTherm = A0, // Датчик температуры
  // Пины модуля RTC
  RTC_SDA = A4,  
  RTC_SCL = A5,
};

#endif