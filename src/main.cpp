#include <Arduino.h>

#define CLK 4
#define DATA 16
#define EN 17

int16_t bitPosition = 0;
uint8_t bitResult = 0;

void CLKReading()
{
    static bool previousBit = false;
    static uint8_t bitReading = 0;
    if (digitalRead(EN) == HIGH)
    {
        if (bitPosition == 0)
        {
            bitReading |= (digitalRead(DATA));
        }
        else
        {
            bitReading |= (digitalRead(DATA) << (bitPosition-1));
        }
        bitPosition++;
    }
    else if (digitalRead(EN) == LOW)
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

void sendByte(byte data) {


  static bool bitCLK = false;
  digitalWrite(EN , LOW);
  digitalWrite(CLK , !bitCLK);
  digitalWrite(CLK , bitCLK);
  //    Serial.printf("%d , %d , %d \n" , 0 , 0, 1);
  for (int i = 0; i < 9; i++) {
    int bitValue = (data >> i) & 0x01;  // Extract the i-th bit from the byte
    bitCLK = !bitCLK;
    digitalWrite(EN , HIGH);
    digitalWrite(DATA, bitValue);
    digitalWrite(CLK , bitCLK);
    //        Serial.printf("%d , %d , %d \n" , bitValue , bitCLK , 1);
  }
  digitalWrite(DATA , 0);
  digitalWrite(EN , LOW);
  digitalWrite(CLK , !bitCLK);
  //    Serial.printf("%d , %d , %d \n" , 0 , 0 , 0);

}


void loop()
{
    // Serial.println(bitPosition);
    // Serial.print(",");

    Serial.println(bitResult);

    // Serial.println(bitResult, DEC);
}