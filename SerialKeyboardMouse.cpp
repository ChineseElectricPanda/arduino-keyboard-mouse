#include "SerialKeyboardMouse.h"

SerialKeyboardMouse::SerialKeyboardMouse(uint32_t baudrate)
: _baudrate(baudrate)
{
}

bool SerialKeyboardMouse::begin(void)
{
    Serial.begin(_baudrate);
    return true;
}

bool SerialKeyboardMouse::end(void)
{
    Serial.end();
    return true;
}

size_t SerialKeyboardMouse::pressKey(uint8_t k)
{
    return VirtualKeyboard::pressKey(k);
}

size_t SerialKeyboardMouse::releaseKey(uint8_t k)
{
    return VirtualKeyboard::releaseKey(k);
}

void SerialKeyboardMouse::releaseAllKeys(void)
{
    return VirtualKeyboard::releaseAllKeys();
}

void SerialKeyboardMouse::clickButton(uint8_t b)
{
    VirtualMouse::clickButton(b);
}

void SerialKeyboardMouse::moveMouse(signed char x, signed char y, signed char wheel)
{
    Serial.print("Mouse: ");
    Serial.print(_buttons);
    Serial.print(" x: ");
    Serial.print(x);
    Serial.print(" y: ");
    Serial.print(y);
    Serial.print(" wheel: ");
    Serial.print(wheel);
    Serial.println();
}

void SerialKeyboardMouse::pressButton(uint8_t b)
{
    VirtualMouse::pressButton(b);
}

void SerialKeyboardMouse::releaseButton(uint8_t b)
{
    VirtualMouse::releaseButton(b);
}

bool SerialKeyboardMouse::isButtonPressed(uint8_t b)
{
    return VirtualMouse::isButtonPressed(b);
}

void SerialKeyboardMouse::sendReport(KeyReport* keys)
{
    Serial.print("Keyboard: ");
    Serial.print(keys->modifiers);
    Serial.print(" keys: ");
    Serial.print(keys->keys[0]);
    Serial.print(" ");
    Serial.print(keys->keys[1]);
    Serial.print(" ");
    Serial.print(keys->keys[2]);
    Serial.print(" ");
    Serial.print(keys->keys[3]);
    Serial.print(" ");
    Serial.print(keys->keys[4]);
    Serial.print(" ");
    Serial.print(keys->keys[5]);
    Serial.print(" ");
    Serial.println();
}