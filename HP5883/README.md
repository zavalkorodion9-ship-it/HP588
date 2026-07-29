# HP5883

Arduino library for the HP5883 / QMC5883P 3-axis magnetometer.

## Features

- Native I2C driver
- No external dependencies
- ESP32
- ESP8266
- AVR
- PlatformIO
- Arduino IDE

## Example

```cpp
#include <HP5883.h>

HP5883 mag;

void setup() {

    Serial.begin(115200);

    if (!mag.begin(20,21)) {

        Serial.println("Sensor not found");

        while(1);

    }

}

void loop() {

    if(mag.update()) {

        Serial.print(mag.getX());
        Serial.print(" ");

        Serial.print(mag.getY());
        Serial.print(" ");

        Serial.println(mag.getZ());

    }

}
```
