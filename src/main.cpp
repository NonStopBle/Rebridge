#include <Arduino.h>

#define CLK 5
#define DATA 15
#define EN 4

int16_t bitPosition = 0;
uint8_t bitResult = 0;

bool previousBit = false;
uint8_t bitReading = 0;

//ACTIVE LOW
void CLKRuning()
{
    if (digitalRead(EN) == LOW)
    {
        if (bitPosition == 0)
        {
            bitReading |= (!digitalRead(DATA));
        }
        else
        {
            bitReading |= (!digitalRead(DATA) << (bitPosition ));
        }
    }
    else if (digitalRead(EN) == HIGH)
    {
    }
}

void CLKReading()
{
    if (digitalRead(EN) == LOW)
    {
        bitPosition++;
        // Serial.printf("%u \n" , bitPosition);
    }
    else if (digitalRead(EN) == HIGH && bitPosition > 0)
    {

        bitResult = bitReading;
        bitReading = 0;
        bitPosition = 0;
    }
}
void setup()
{
    pinMode(CLK, INPUT);
    pinMode(DATA, INPUT);
    pinMode(EN, INPUT);

    attachInterrupt(CLK, CLKReading, CHANGE);
    // attachInterrupt(EN, CLKReading, CHANGE);

    Serial.begin(115200);
}

void sendByte(byte data)
{

    static bool bitCLK = false;
    digitalWrite(EN, LOW);
    digitalWrite(CLK, !bitCLK);
    digitalWrite(CLK, bitCLK);
    //    Serial.printf("%d , %d , %d \n" , 0 , 0, 1);
    for (int i = 0; i < 9; i++)
    {
        int bitValue = (data >> i) & 0x01; // Extract the i-th bit from the byte
        bitCLK = !bitCLK;
        digitalWrite(EN, HIGH);
        digitalWrite(DATA, bitValue);
        digitalWrite(CLK, bitCLK);
        //        Serial.printf("%d , %d , %d \n" , bitValue , bitCLK , 1);
    }
    digitalWrite(DATA, 0);
    digitalWrite(EN, LOW);
    digitalWrite(CLK, !bitCLK);
    //    Serial.printf("%d , %d , %d \n" , 0 , 0 , 0);
}
//after
static int bufferCounter = 0;
void loop()
{

    CLKRuning();

    if (bufferCounter++ < 100)
    {
    }
    else
    {
        Serial.println(bitResult, DEC);
        bufferCounter = 0;
    }
    // Serial.println(bitPosition);
    // Serial.print(",");
    // static uint32_t previous = 0;
    // if (millis() - previous > 100)
    // {
    // Serial.print(bitPosition);
    // Serial.print(",");
    // Serial.print(!digitalRead(EN));
    // Serial.print(",");
    // Serial.print(!digitalRead(DATA));
    // Serial.print(",");
    // Serial.print(!digitalRead(CLK));
    // Serial.print(",");
    // Serial.print(bitResult, BIN);
    // Serial.print(",");

    // bitReading = 0;
    // previous = millis();
    // }
    // if(!digitalRead(DATA) == HIGH){
    //     Serial.print("bit:");
    //     uint8_t bitShifter = (!digitalRead(DATA) << (bitPosition - 1));
    //     Serial.print(bitShifter , BIN);
    //     Serial.print(",");
    // }

    // Serial.println(bitResult, BIN);
}