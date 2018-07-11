#ifndef SerialKeyboardMouse_h
#define SerialKeyboardMouse_h

#include "KeyboardMouse.h"
#include "VirtualKeyboard.h"
#include "VirtualMouse.h"

class SerialKeyboardMouse : public KeyboardMouse, private VirtualKeyboard, private VirtualMouse
{
public:
    SerialKeyboardMouse(uint32_t baudrate);
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
    uint32_t _baudrate;

    void sendReport(KeyReport* keys);
};
#endif