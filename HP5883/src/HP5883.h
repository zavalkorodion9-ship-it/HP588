#pragma once

#include <Arduino.h>
#include <Wire.h>

class HP5883 {

public:

    bool begin(uint8_t sda, uint8_t scl);
    bool update();

    int16_t getX();
    int16_t getY();
    int16_t getZ();

private:

    static const uint8_t ADDRESS = 0x2C;

    int16_t x = 0;
    int16_t y = 0;
    int16_t z = 0;

    void writeReg(uint8_t reg, uint8_t value);
    uint8_t readReg(uint8_t reg);
    int16_t read16(uint8_t reg);
};
