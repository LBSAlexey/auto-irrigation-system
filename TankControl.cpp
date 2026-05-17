#include "TankControl.h"

TankCondition TankControl::tankCheck(TankCondition tankStatus) 
{
  this->upperLevel = digitalRead((uint8_t)DigitalPinsInput::UpperLevel);
  this->lowerLevel = digitalRead((uint8_t)DigitalPinsInput::LowerLevel);

  if((!upperLevel && !lowerLevel) || tankStatus == TankCondition::EMPTY) return fillingTank();
  if(upperLevel && lowerLevel) return TankCondition::FULL;
  if(!upperLevel && lowerLevel) return TankCondition::MIDDLE;

}


TankCondition TankControl::fillingTank() 
{
  while(true) 
  {
    this->upperLevel = digitalRead((uint8_t)DigitalPinsInput::UpperLevel);
    this->lowerLevel = digitalRead((uint8_t)DigitalPinsInput::LowerLevel);

    if(!upperLevel && !lowerLevel) digitalWrite((uint8_t)DigitalPinsOutput::RelayPit, HIGH);
    if(!upperLevel && lowerLevel) this->tankStatus = TankCondition::MIDDLE;
    if(upperLevel && lowerLevel) 
    {
      digitalWrite((uint8_t)DigitalPinsOutput::RelayPit, LOW);
      return TankCondition::FULL; 
    }
  }
}

void TankControl::handleIrrigation() 
{
  tankCheck(this->tankStatus);
}