#ifndef UsbKeyboardMouse_h
#define UsbKeyboardMouse_h

#include <HID.h>
#if defined(_USING_HID)

#include "KeyboardMouse.h"
#include <Mouse.h>
#include <Keyboard.h>

class UsbKeyboardMouse : public KeyboardMouse, private Keyboard_, private Mouse_
{
public:
    UsbKeyboardMouse(void);
    bool begin(void);
    bool end(void);
    size_t pressKey(uint8_t k);
    size_t releaseKey(uint8_t k);
    void releaseAllKeys(void);
    void clickButton(uint8_t b = 1);
    void moveMouse(signed char x, signed char y, signed char wheel = 0); 
    void pressButton(uint8_t b = 1);   // press LEFT by default
    void releaseButton(uint8_t b = 1); // release LEFT by default
    bool isButtonPressed(uint8_t b = 1); // check LEFT by default
private:
    Keyboard_ keyboard;
    Mouse_ mouse;
};
#endif
#endif