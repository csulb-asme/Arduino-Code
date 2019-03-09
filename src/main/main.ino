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

#define LED_GREEN 5
#define LED_WHITE 6
#define LED_BLUE 10
#define LED_PINK 11
#define LED_IDK 12

void setup()
{
    BTSerial.flush();
    delay(25);
    BTSerial.begin(9600);
    Serial.begin(9600);  //Sets the baud for serial data transmission
    
    pinMode(LED_IDK, OUTPUT);
    pinMode(LED_PINK, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_WHITE, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
}

void doDoor(int value) {
  if (value == 1) {
    analogWrite(LED_WHITE, 255);
  } else if (value == 0) {
    analogWrite(LED_WHITE, 0);
  }
}

void doLever(int value) {
  if (value == 1) {
    analogWrite(LED_GREEN, 255);
  } else if (value == 0) {
    analogWrite(LED_GREEN, 0);
  }
}

void doVertical(int value) {
  int tempPercentage;
  int tempRange;
  if (value == 0) {
    analogWrite(11, 0);
  } else if ((value % 2) == 0) { // Even Number
    tempPercentage = (value / 32720);
    tempRange = 255 * tempPercentage;
    analogWrite(11, tempRange);
  }
} 

void loop()
{
    if (Serial.available() >= 25) // Send data only when you receive data:
    {
        movementVertical = Serial.parseInt();
        Serial.print("Vertical: ");
        Serial.println(movementVertical);
        doVertical(movementVertical);

        movementHorizontal = Serial.parseInt();
        Serial.print("Horizontal: ");
        Serial.println(movementHorizontal);

        movementRotation = Serial.parseInt();
        Serial.print("Rotation: ");
        Serial.println(movementRotation);
  
        lever = Serial.parseInt();
        Serial.print("Lever: ");
        Serial.println(lever);
        doLever(lever);

        door = Serial.parseInt();
        Serial.print("Door: ");
        Serial.println(door);
        doDoor(door);
    }
}
