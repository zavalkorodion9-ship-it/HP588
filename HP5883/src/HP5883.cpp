#include "HP5883.h"

void HP5883::writeReg(uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(ADDRESS);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t HP5883::readReg(uint8_t reg)
{
    Wire.beginTransmission(ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDRESS, (uint8_t)1);

    if (Wire.available())
        return Wire.read();

    return 0;
}

int16_t HP5883::read16(uint8_t reg)
{
    Wire.beginTransmission(ADDRESS);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDRESS, (uint8_t)2);

    uint8_t low = Wire.read();
    uint8_t high = Wire.read();

    return (int16_t)((high << 8) | low);
}
bool HP5883::begin(uint8_t sda, uint8_t scl)
{
    Wire.begin(sda, scl);

    // Проверяем Chip ID
    if (readReg(0x00) != 0x80)
        return false;

    // Инициализация HP5883/QMC5883P
    writeReg(0x0D, 0x40);
    delay(10);

    writeReg(0x29, 0x06);
    delay(10);

    writeReg(0x0A, 0xCF);
    delay(50);

    return true;
}
bool HP5883::update()
{
    uint8_t status = readReg(0x09);

    // Нет новых данных
    if ((status & 0x01) == 0)
        return false;

    x = read16(0x01);
    y = read16(0x03);
    z = read16(0x05);

    return true;
}
int16_t HP5883::getX()
{
    return x;
}

int16_t HP5883::getY()
{
    return y;
}

int16_t HP5883::getZ()
{
    return z;
}
