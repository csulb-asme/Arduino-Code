#include <SoftwareSerial.h>
#define RxD 10
#define TxD 11
String data; //Variable for storing received data
int movementVertical;
int movementHorizontal;
int movementRotation;
int lever;
int door;
char c;
SoftwareSerial BTSerial(RxD, TxD);

void setup()
{
    BTSerial.flush();
    delay(25);
    BTSerial.begin(9600);
    Serial.begin(9600);  //Sets the baud for serial data transmission
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{
    if (Serial.available() >= 24) // Send data only when you receive data:
    {
        movementVertical = Serial.parseInt();
        Serial.print("Vertical: ");
        Serial.println(movementVertical);

        movementHorizontal = Serial.parseInt();
        Serial.print("Horizontal: ");
        Serial.println(movementHorizontal);

        movementRotation = Serial.parseInt();
        Serial.print("Rotation: ");
        Serial.println(movementRotation);

        lever = Serial.parseInt();
        Serial.print("Lever: ");
        Serial.println(lever);

        door = Serial.parseInt();
        Serial.print("Door: ");
        Serial.println(door);
    }
}
