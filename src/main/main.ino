#include <SoftwareSerial.h>
#define RxD 10
#define TxD 11
String data; //Variable for storing received data
int firstSet;
int secondSet;
SoftwareSerial BTSerial(RxD, TxD);

#define PIN_LEVER 11

void setup()
{
    BTSerial.flush();
    delay(25);
    BTSerial.begin(9600);
    Serial.begin(9600);  //Sets the baud for serial data transmission
    
    pinMode(PIN_LEVER, OUTPUT);
}

void loop()
{
    if (Serial.available() >= 8) // Send data only when you receive data:
    {
        firstSet = Serial.parseInt();
        Serial.print(firstSet);

        // Axis Movement - Up Down
        if (firstSet == 0) {
          secondSet = Serial.parseInt();

        // Axis Movement - Left Right
        } else if (firstSet == 1) {
          secondSet = Serial.parseInt();

        // Axis Rotation - Left Right
        } else if (firstSet == 2) {
          secondSet = Serial.parseInt();

        // Button A - Up
        } else if (firstSet == 3) {
          secondSet = Serial.parseInt();
            if (secondSet == 1) {
              analogWrite(PIN_LEVER, 255);
            } else if (secondSet == 0) {
              analogWrite(PIN_LEVER, 0);
            }
        // Button B - Down
        } else if (firstSet == 4) {
          secondSet = Serial.parseInt();

            if (secondSet == 1) {
              analogWrite(PIN_LEVER, 255);
            } else if (secondSet == 0) {
              analogWrite(PIN_LEVER, 0);
            }
          
        }
    }
}
