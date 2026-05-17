#include "SystemControl.h"

void SystemControl::systemStatusCheck() 
{
  switch(this->currentStatus) 
  {
    case SystemStatus::STOP:
      SystemControl::systemStop();
      break;

    case SystemStatus::RUN:
      SystemControl::systemRun();
      break;
      
    case SystemStatus::ERROR:
      SystemControl::systemError();
      break;
  }
}

void SystemControl::setSystemStatus(SystemStatus currentStatus) 
{
  this->currentStatus = currentStatus;
}

SystemStatus SystemControl::getSystemStatus() 
{
  return this->currentStatus;
}

void SystemControl::systemStop() // Полностью останавливаем систему
{
  digitalWrite((uint8_t)DigitalPinsOutput::LedStop, HIGH);
  digitalWrite((uint8_t)DigitalPinsOutput::LedStart, LOW);
  digitalWrite((uint8_t)DigitalPinsOutput::RelayPit, LOW);
  digitalWrite((uint8_t)DigitalPinsOutput::RelayBarrel, LOW);
}

void SystemControl::systemRun() 
{
  digitalWrite((uint8_t)DigitalPinsOutput::LedStop, LOW);
  digitalWrite((uint8_t)DigitalPinsOutput::LedStart, HIGH);
}

void SystemControl::systemError() 
{
  digitalWrite((uint8_t)DigitalPinsOutput::LedStop, HIGH);
  digitalWrite((uint8_t)DigitalPinsOutput::LedStart, HIGH);
}
