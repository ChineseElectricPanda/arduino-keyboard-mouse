#ifndef VirtualMouse_h
#define VirtualMouse_h

#include <stdint.h>
#include <Arduino.h>

#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_MIDDLE 4
#define MOUSE_ALL (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE)

class VirtualMouse
{
protected:
  uint8_t _buttons;
  void buttons(uint8_t b);
public:
  VirtualMouse(void);
  virtual bool begin(void) = 0;
  virtual bool end(void) = 0;
  void clickButton(uint8_t b = MOUSE_LEFT);
  virtual void moveMouse(signed char x, signed char y, signed char wheel = 0) = 0; 
  void pressButton(uint8_t b = MOUSE_LEFT);   // press LEFT by default
  void releaseButton(uint8_t b = MOUSE_LEFT); // release LEFT by default
  bool isButtonPressed(uint8_t b = MOUSE_LEFT); // check LEFT by default
};
#endif