#ifndef TANKCONTROL_H
#define TANKCONTROL_H
#include "SystemControl.h"
#include "TankCondition.h"

class TankControl // состояние баков
{

private:
  SystemControl& systemControl; // Объект экзепляра класса SystemControl

  TankCondition tankStatus = TankCondition::EMPTY; // Текущее состояния бака
  bool upperLevel; // Верхний датчик
  bool lowerLevel; // Нижний датчик

public:

TankControl(SystemControl& sys) : systemControl(sys) {} // Конструктор


  TankCondition tankCheck(TankCondition tankStatus); // Проверка бака на уровень воры
  TankCondition fillingTank(); // Наполнение бака
  void handleIrrigation();     // Включение насоса на поливяя
};


#endif