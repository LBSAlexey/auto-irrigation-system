#include "SystemControl.h"

void SystemControl::systemStatusCheck(SystemStatus currentStatus) 
{
  switch(currentStatus) 
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
void SystemControl::systemStop() 
{
  digitalWrite((uint8_t)DigitalPinsOutput::LedStop, HIGH);
  digitalWrite((uint8_t)DigitalPinsOutput::LedStart, LOW);
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
