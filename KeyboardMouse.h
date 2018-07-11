#ifndef KeyboardMouse_h
#define KeyboardMouse_h

#include "HID.h"

class KeyboardMouse
{
public:
    virtual bool begin(void) = 0;
    virtual bool end(void) = 0;
    virtual size_t pressKey(uint8_t k) = 0;
    virtual size_t releaseKey(uint8_t k) = 0;
    virtual void releaseAllKeys(void) = 0;
    virtual void clickButton(uint8_t b = 1) = 0;
    virtual void moveMouse(signed char x, signed char y, signed char wheel = 0) = 0;
    virtual void pressButton(uint8_t b = 1) = 0;   // press LEFT by default
    virtual void releaseButton(uint8_t b = 1) = 0; // release LEFT by default
    virtual bool isButtonPressed(uint8_t b = 1) = 0; // check LEFT by default
};

#endif