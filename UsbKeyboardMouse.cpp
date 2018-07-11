#include "UsbKeyboardMouse.h"

#if defined(_USING_HID)

UsbKeyboardMouse::UsbKeyboardMouse(void)
{
}

bool UsbKeyboardMouse::begin(void)
{
    this->Keyboard_::begin();
    this->Mouse_::begin();
    return true;
}

bool UsbKeyboardMouse::end(void)
{
    this->Keyboard_::end();
    this->Mouse_::end();
    return true;
}

size_t UsbKeyboardMouse::pressKey(uint8_t k)
{
    return this->Keyboard_::press(k);
}

size_t UsbKeyboardMouse::releaseKey(uint8_t k)
{
    return this->Keyboard_::release(k);
}

void UsbKeyboardMouse::releaseAllKeys(void)
{
    this->Keyboard_::releaseAll();
}

void UsbKeyboardMouse::clickButton(uint8_t b)
{
    this->Mouse_::click(b);
}

void UsbKeyboardMouse::moveMouse(signed char x, signed char y, signed char wheel)
{
    this->Mouse_::move(x, y, wheel);
}

void UsbKeyboardMouse::pressButton(uint8_t b)
{
    this->Mouse_::press(b);
}

void UsbKeyboardMouse::releaseButton(uint8_t b)
{
    this->Mouse_::release(b);
}

bool UsbKeyboardMouse::isButtonPressed(uint8_t b)
{
    return this->Mouse_::isPressed(b);
}
#endif