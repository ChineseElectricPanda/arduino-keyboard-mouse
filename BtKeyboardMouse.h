#ifndef BtKeyboardMouse_h
#define BtKeyboardMouse_h

#include "KeyboardMouse.h"
#include <SoftwareSerial.h>
#include "VirtualKeyboard.h"
#include "VirtualMouse.h"

class BtKeyboardMouse : public KeyboardMouse, private VirtualKeyboard, private VirtualMouse
{
public:
    BtKeyboardMouse(uint8_t rx, uint8_t tx, char name[]);
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
    SoftwareSerial _btSerial;
    char _name[];
    
    void sendReport(KeyReport* keys);
    bool getBtInput(char str[], uint8_t strlen);
};
#endif