#ifndef SYSTEMCONTROL_H
#define SYSTEMCONTROL_H
#include "SystemStatus.h"
#include "Pins.h"

class SystemControl 
{

private:
  SystemStatus currentStatus = SystemStatus::STOP; // Текущий статус системы
  uint8_t LedStart = (uint8_t)DigitalPinsOutput::LedStart; // Светодиоды
  uint8_t LedStop = (uint8_t)DigitalPinsOutput::LedStop;

public:
  
  SystemControl() // конструктор
  {
    systemStatusCheck();
  }

  void setSystemStatus(SystemStatus currentStatus); // сеттер
  SystemStatus getSystemStatus();

  void systemStatusCheck(); // Проверка на текущий статус системы
  void systemStop();  // Алгоритм остановленной системы
  void systemRun();   // Алгоритм запущенной системы
  void systemError(); // Алгоритм системы в ошибке

  SystemStatus systemStopToRun(SystemStatus& currentStatus);
  SystemStatus systemRunToStop(SystemStatus& currentStatus);
  SystemStatus systemRunToError(SystemStatus& currentStatus);
  SystemStatus systemErrorToStop(SystemStatus& currentStatus);

};

#endif