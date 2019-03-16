#include <SoftwareSerial.h>
#define RxD 10
#define TxD 11

SoftwareSerial BTSerial(RxD, TxD);

String data; //Variable for storing received data
int firstSet;
int secondSet;


// SPEED CONSTANTS
#define FORWARD 83
#define BACKWARD 220
#define STOP 255


// MOTOR PINS
#define MOTOR_FL 12
#define MOTOR_FR 11
#define MOTOR_BL 10
#define MOTOR_BR 13
#define MOTOR_LL 8
#define MOTOR_LR 7
#define MOTOR_TL 6
#define MOTOR_TR 5
#define MOTOR_DL 4
#define MOTOR_DR 3

void setup()
{
    BTSerial.flush();
    delay(25);
    BTSerial.begin(9600);
    Serial.begin(9600);  //Sets the baud for serial data transmission

    pinMode(MOTOR_FL, OUTPUT);
    pinMode(MOTOR_FR, OUTPUT);
    pinMode(MOTOR_DL, OUTPUT);
    pinMode(MOTOR_DR, OUTPUT);
    pinMode(MOTOR_LR, OUTPUT);
    pinMode(MOTOR_LL, OUTPUT);
    pinMode(MOTOR_TL, OUTPUT);
    pinMode(MOTOR_TR, OUTPUT);
    pinMode(MOTOR_BL, OUTPUT);
    pinMode(MOTOR_BR, OUTPUT);
}

void loop()
{
    if (Serial.available() >= 8) // Send data only when you receive data:
    {
        firstSet = Serial.parseInt();
        Serial.print(firstSet);
        secondSet = Serial.parseInt();
        Serial.print(secondSet);
        // FORWARD FUNCTION

        // UP
        if (firstSet == 11) {
            if (secondSet == 1) {
                analogWrite(MOTOR_FL, BACKWARD);
                analogWrite(MOTOR_BL, BACKWARD);
                analogWrite(MOTOR_FR, FORWARD);
                analogWrite(MOTOR_BR, FORWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            } else {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            }

            // DOWN
        } else if (firstSet == 12) {
            if (secondSet == 1) {
                analogWrite(MOTOR_FL, FORWARD);
                analogWrite(MOTOR_BL, FORWARD);
                analogWrite(MOTOR_FR, BACKWARD);
                analogWrite(MOTOR_BR, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            } else {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            }

            // LEFT
        } else if (firstSet == 13) {
            if (secondSet == 1) {
                analogWrite(MOTOR_FL, BACKWARD);
                analogWrite(MOTOR_BL, FORWARD);
                analogWrite(MOTOR_FR, BACKWARD);
                analogWrite(MOTOR_BR, FORWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            } else {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            }

            // RIGHT
        } else if (firstSet == 14) {
            if (secondSet == 1) {
                analogWrite(MOTOR_FL, FORWARD);
                analogWrite(MOTOR_BL, BACKWARD);
                analogWrite(MOTOR_FR, FORWARD);
                analogWrite(MOTOR_BR, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            } else {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            }

            // A BUTTON -- LEFT LEVER UP
        } else if (firstSet == 0) {
            if (secondSet == 1) {
                analogWrite(MOTOR_LL, FORWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_LL, STOP);
            } else {
                analogWrite(MOTOR_LL, STOP);
            }

            // B BUTTON -- LEFT LEVER DOWN
        } else if (firstSet == 1) {
            if (secondSet == 1) {
                analogWrite(MOTOR_LL, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_LL, STOP);
            } else {
                analogWrite(MOTOR_LL, STOP);
            }

            // Y BUTTON -- RIGHT LEVER UP
        } else if (firstSet == 2) {
            if (secondSet == 1) {
                analogWrite(MOTOR_LR, 120);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_LR, STOP);
            } else {
                analogWrite(MOTOR_LR, STOP);
            }

            // Y BUTTON -- RIGHT LEVER DOWN
        } else if (firstSet == 3) {
            if (secondSet == 1) {
                analogWrite(MOTOR_LR, 190);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_LR, STOP);
            } else {
                analogWrite(MOTOR_LR, STOP);
            }

            // LEFT BUMPER -- 
        } else if (firstSet == 9) {
            if (secondSet == 1) {
                analogWrite(MOTOR_DR, FORWARD);
                analogWrite(MOTOR_DL, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_DR, STOP);
                analogWrite(MOTOR_DL, STOP);
            } else {
                analogWrite(MOTOR_DR, STOP);
                analogWrite(MOTOR_DL, STOP);
            }
        } else if (firstSet == 10) {
            if (secondSet == 1) {
                analogWrite(MOTOR_DR, BACKWARD);
                analogWrite(MOTOR_DL, FORWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_DR, STOP);
                analogWrite(MOTOR_DL, STOP);
            } else {
                analogWrite(MOTOR_DR, STOP);
                analogWrite(MOTOR_DL, STOP);
            }
        } else if (firstSet == 4) {
            if (secondSet == 1) {
                analogWrite(MOTOR_FL, FORWARD);
                analogWrite(MOTOR_FR, BACKWARD);
                analogWrite(MOTOR_BL, FORWARD);
                analogWrite(MOTOR_BR, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            } else {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            }
        } else if (firstSet == 6) {
            if (secondSet == 1) {
                analogWrite(MOTOR_FL, FORWARD);
                analogWrite(MOTOR_FR, BACKWARD);
                analogWrite(MOTOR_BL, FORWARD);
                analogWrite(MOTOR_BR, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            } else {
                analogWrite(MOTOR_FL, STOP);
                analogWrite(MOTOR_BL, STOP);
                analogWrite(MOTOR_FR, STOP);
                analogWrite(MOTOR_BR, STOP);
            }
        } else if (firstSet == 7) {
            if (secondSet == 1) {
                analogWrite(MOTOR_DL, FORWARD);
                analogWrite(MOTOR_DR, FORWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_DL, STOP);
                analogWrite(MOTOR_DR, STOP);
            } else {
                analogWrite(MOTOR_DL, STOP);
                analogWrite(MOTOR_DR, STOP);
            }
        } else if (firstSet == 8) {
            if (secondSet == 1) {
                analogWrite(MOTOR_DL, BACKWARD);
                analogWrite(MOTOR_DR, BACKWARD);
            } else if (secondSet == 0) {
                analogWrite(MOTOR_DL, STOP);
                analogWrite(MOTOR_DR, STOP);
            } else {
                analogWrite(MOTOR_DL, STOP);
                analogWrite(MOTOR_DR, STOP);
            }
        }
    }
}
