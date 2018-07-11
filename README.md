# Arduino Keyboard and Mouse Library
This library allows the Arduino to act as a keyboard and mouse input device via USB (Leonardo/Micro), Bluetooth (RN-42), or Serial (used for debugging).

# Installation
Create a folder in your Arduino libraries folder, and put all files from this repository into it.

On Windows this should be in `C:\Users\<username>\Documents\Arduino\libraries`

# Usage
## USB
Using the Arduino as a USB HID requires a Leonardo or Micro board.

```c++
#include <UsbKeyboardMouse.h>
UsbKeyboardMouse kbm;
...
kbm.pressKey('a');
```

## Bluetooth
Using the Arduino as a Bluetooth HID requires an RN-42 Bluetooth module.

TX of the Bluetooth module is connected to `RX_PIN` (must be an interrupt pin)

RX of the Bluetooth module is connected to `TX_PIN`

`DEVICE_NAME` is the name that will show up when searching for the Bluetooth device.

```c++
#include <BtKeyboardMouse.h>
BtKeyboardMouse kbm(RX_PIN, TX_PIN, DEVICE_NAME);
...
kbm.pressKey('a');
```

## Serial
The serial interface is included as a debugging tool. Mouse movements and keypresses are printed to the Arduino's serial interface.

`BAUDRATE` is the baudrate used for the serial communication.

```c++
#include <SerialKeyboardMouse.h>
SerialKeyboardMouse kbm(BAUDRATE);
...
kbm.pressKey('a');
```
