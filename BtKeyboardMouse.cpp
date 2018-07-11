#include "BtKeyboardMouse.h"

BtKeyboardMouse::BtKeyboardMouse(uint8_t rx, uint8_t tx, char name[])
: _btSerial(rx, tx)
{
    strcpy(_name, name);
}

bool BtKeyboardMouse::begin(void)
{
    _btSerial.begin(115200);
    // Enter command mode
    delay(500);
    _btSerial.print("$$$");
    //delay(50);
    if(!getBtInput("CMD\r\n", 5)) return false;
    // Set pairing mode
    //delay(50);
    _btSerial.print("SM,6\r\n");
    //delay(50);
    if(!getBtInput("AOK\r\n", 5)) return false;
    // Set name
    //delay(50);
    _btSerial.print("SN,");
    _btSerial.print(_name);
    _btSerial.print("\r\n");
    //delay(50);
    if(!getBtInput("AOK\r\n", 5)) return false;
    // Set HID profile
    //delay(50);
    _btSerial.print("S~,6\r\n");
    //delay(50);
    if(!getBtInput("AOK\r\n", 5)) return false;
    // Set combo report descriptor
    //delay(50);
    _btSerial.print("SH,0230\r\n");
    //delay(50);
    if(!getBtInput("AOK\r\n", 5)) return false;
    // Reboot
    //delay(50);
    _btSerial.print("R,1\r\n");
    //delay(50);
    if(!getBtInput("Reboot!\r\n", 9)) return false;
    // Wait for startup
    delay(1000);
    return true;
}

bool BtKeyboardMouse::end(void)
{
    _btSerial.end();
    return true;
}

size_t BtKeyboardMouse::pressKey(uint8_t k)
{
    return VirtualKeyboard::pressKey(k);
}

size_t BtKeyboardMouse::releaseKey(uint8_t k)
{
    return VirtualKeyboard::releaseKey(k);
}

void BtKeyboardMouse::releaseAllKeys(void)
{
    return VirtualKeyboard::releaseAllKeys();
}

void BtKeyboardMouse::clickButton(uint8_t b)
{
    VirtualMouse::clickButton(b);
}

void BtKeyboardMouse::moveMouse(signed char x, signed char y, signed char wheel)
{
    _btSerial.write((byte)0xFD);
    _btSerial.write((byte)0x05);
    _btSerial.write((byte)0x02);
    _btSerial.write((byte)_buttons);
    _btSerial.write((byte)x);
    _btSerial.write((byte)y);
    _btSerial.write((byte)wheel);
}

void BtKeyboardMouse::pressButton(uint8_t b)
{
    VirtualMouse::pressButton(b);
}

void BtKeyboardMouse::releaseButton(uint8_t b)
{
    VirtualMouse::releaseButton(b);
}

bool BtKeyboardMouse::isButtonPressed(uint8_t b)
{
    return VirtualMouse::isButtonPressed(b);
}

/**
 * Sends a raw keyboard report
 * References:
 *  https://github.com/baselsw/BPLib/blob/master/BPLib.cpp
 *  https://cdn.sparkfun.com/datasheets/Wireless/Bluetooth/RN-HID-User-Guide-v1.0r.pdf
 *    (page 6)
 */
void BtKeyboardMouse::sendReport(KeyReport* keys)
{
    _btSerial.write((byte)0xFD);
    _btSerial.write((byte)0x09);
    _btSerial.write((byte)0x01);
    _btSerial.write((byte)keys->modifiers);
    _btSerial.write((byte)keys->keys[0]);
    _btSerial.write((byte)keys->keys[1]);
    _btSerial.write((byte)keys->keys[2]);
    _btSerial.write((byte)keys->keys[3]);
    _btSerial.write((byte)keys->keys[4]);
    _btSerial.write((byte)keys->keys[5]);
}

bool BtKeyboardMouse::getBtInput(char str[], uint8_t strlen)
{
    // Input buffer
    char buffer[strlen + 1];
    // Wait for requested number of bytes to become available
    uint8_t waited = 0;
    while(_btSerial.available() < strlen && waited < 20)
    {
        delay(1);
        waited++;
    }
    if(waited >= 20)
    {
        // Timed out
        return false;
    }
    // Read requested number of bytes
    for(int i = 0; i < strlen; i++)
    {
        buffer[i] = (char)_btSerial.read();
    }
    // Append null terminator to string
    buffer[strlen] = 0;

    return strcmp(buffer, str) == 0;
}