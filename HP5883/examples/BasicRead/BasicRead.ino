#include <HP5883.h>

HP5883 mag;

void setup()
{
    Serial.begin(115200);

    if (!mag.begin(20, 21))
    {
        Serial.println("HP5883 not found");

        while (1)
            delay(1000);
    }

    Serial.println("HP5883 OK");
}

void loop()
{
    if (mag.update())
    {
        Serial.print("X=");
        Serial.print(mag.getX());

        Serial.print(" Y=");
        Serial.print(mag.getY());

        Serial.print(" Z=");
        Serial.println(mag.getZ());
    }

    delay(100);
}
