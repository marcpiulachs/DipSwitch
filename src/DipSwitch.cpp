#include "Arduino.h"
#include "DipSwitch.h"

DipSwitch::DipSwitch(int pins[])
{
    _pins = pins;
    //_numberOfPins = (int)(sizeof(_pins) / sizeof(_pins[0]));
    _numberOfPins = sizeof(_pins) / sizeof(int);

    for (int i = 0; i < _numberOfPins; i++)
    {
        pinMode(_pins[i], INPUT_PULLUP);
    }
}

int DipSwitch::read()
{
    int value = 0;
    for (int i = 0; i < _numberOfPins; i++)
    {
        value += digitalRead(_pins[i]) << i;
    }
    return value;
}
