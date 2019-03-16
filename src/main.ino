#include <SoftwareSerial.h>
#include <Servo.h>

#define RxD 10
#define TxD 11

SoftwareSerial BTSerial(RxD, TxD);

String data;
int mode;
int state;

#define forward 11 //dpad up
#define backward 12 //dpad down
#define left 13 //dpad left
#define right 14 //dpad right

#define rlever_up 0 //a 
#define rlever_down 1 //b

#define llever_up 2 //y
#define llever_down 3 //x

#define door_up 7
#define door_down 8

#define trap_up 9
#define trap_down 10

//SPEED CONSTANTS
#define FULL_FWD 0
#define HALF_FWD 45
#define STOP 91
#define HALF_BKWD 135
#define FULL_BKWD 180

//MOTOR PINS
#define FRONTLEFT 12
#define FRONTRIGHT 11
#define BACKLEFT 10
#define BACKRIGHT 7
#define LEVERLEFT 8
#define LEVERRIGHT 13
#define TRAPLEFT 6
#define TRAPRIGHT 7
#define DOORLEFT 4
#define DOORRIGHT 3

//MOVEMENT
Servo MOTOR_FL;
Servo MOTOR_FR;
Servo MOTOR_BL;
Servo MOTOR_BR;

//LEVER
Servo MOTOR_LL;
Servo MOTOR_LR;

//TRAP DOOR
Servo MOTOR_TL;
Servo MOTOR_TR;

//BACK DOOR
Servo MOTOR_DL;
Servo MOTOR_DR;

void setup() {

    // FLUSH old bluetooth
    BTSerial.flush();
    delay(5);

    BTSerial.begin(9600);
    Serial.begin(9600);

    // HOOKUP MOVEMENT
    MOTOR_FL.attach(FRONTLEFT);
    MOTOR_FR.attach(FRONTRIGHT);
    MOTOR_BL.attach(BACKLEFT);
    MOTOR_BR.attach(BACKRIGHT);

    // HOOKUP LEVER
    MOTOR_LL.attach(LEVERLEFT);
    MOTOR_LR.attach(LEVERRIGHT);

    // HOOKUP TRAP DOOR
    MOTOR_TL.attach(TRAPLEFT);
    MOTOR_TR.attach(TRAPRIGHT);

    // HOOKUP BACKDOOR
    MOTOR_DL.attach(DOORLEFT);
    MOTOR_DR.attach(DOORRIGHT);
}


void stopMovement() {
    MOTOR_FL.write(STOP);
    MOTOR_FR.write(STOP);
    MOTOR_BL.write(STOP);
    MOTOR_BR.write(STOP);
}


void goForward() {
    MOTOR_FL.write(HALF_FWD);
    MOTOR_FR.write(HALF_FWD);
    MOTOR_BL.write(HALF_FWD);
    MOTOR_BR.write(HALF_FWD);
}

void goBackward() {
    MOTOR_FL.write(HALF_BKWD);
    MOTOR_FR.write(HALF_BKWD);
    MOTOR_BL.write(HALF_BKWD);
    MOTOR_BR.write(HALF_BKWD);
}

void goLeft() {
    MOTOR_FL.write(HALF_BKWD);
    MOTOR_BL.write(HALF_FWD);
    MOTOR_FR.write(HALF_FWD);
    MOTOR_BR.write(HALF_BKWD);
}

void goRight() {
    MOTOR_FL.write(HALF_FWD);
    MOTOR_BL.write(HALF_BKWD);
    MOTOR_FR.write(HALF_BKWD);
    MOTOR_BR.write(HALF_FWD);
}

void leftLever(int val) {
    if (val == 1) {
        MOTOR_LL.write(80);
        delay(10);
    } else if (val == 2) {
        MOTOR_LL.write(100);
        delay(10);
    } else {
        MOTOR_LL.write(STOP);
        delay(10);
    }
}

void rightLever(int val) {
    if (val == 1) {
        MOTOR_LR.write(80);
        delay(10);
    } else if (val == 2) {
        MOTOR_LR.write(100);
        delay(10);
    } else {
        MOTOR_LR.write(STOP);
        delay(10);
    }
}

void trapDoor(int val) {
    if (val == 1) {
        MOTOR_TL.write(80);
        MOTOR_TR.write(80);
        delay(10);
    } else if (val == 2) {
        MOTOR_TL.write(100);
        MOTOR_TR.write(100);
        delay(10);
    } else {
        MOTOR_TL.write(STOP);
        MOTOR_TR.write(STOP);
        delay(10);
    }
}

void backDoor(int val) {
    if (val == 1) {
        MOTOR_DL.write(80);
        MOTOR_DR.write(80);
        delay(10);
    } else if (val == 2) {
        MOTOR_DL.write(100);
        MOTOR_DR.write(100);
        delay(10);
    } else {
        MOTOR_DL.write(STOP);
        MOTOR_DR.write(STOP);
        delay(10);
    }
}

void loop() {
    if (Serial.available() >= 4) {
        mode = Serial.parseInt();
        Serial.println(mode);
        state = Serial.parseInt();
        Serial.println(state);

        // FORWARD
        if (mode == forward) 
        {
            if (state == 1) 
            {
                goForward();
            } 
            else if (state == 0) 
            {
                stopMovement();
            } 
            else 
            {
                stopMovement();
            }
        }

        // BACKWARD
        if (mode == backward)
        {
            if (state == 1)
            {
                goBackward();
            }
            else if (state == 0)
            {
                stopMovement();
            }
            else
            {
                stopMovement();
            }
        }

        // LEFT
        if (mode == left)
        {
            if (state == 1)
            {
                goLeft();
            }
            else if (state == 0)
            {
                stopMovement();
            }
            else
            {
                stopMovement();
            }
        }

        // RIGHT
        if (mode == right)
        {
            if (state == 1)
            {
                goRight();
            }
            else if (state == 0)
            {
                stopMovement();
            }
            else
            {
                stopMovement();
            }
        }

        if (mode == rlever_up) {
            if (state == 1) 
            {
                rightLever(1);
            }
            else if (state == 0)
            {
                rightLever(3);
            }
            else
            {
                rightLever(3);
            }
        }

        if (mode == rlever_down)
        {
            if (state == 1)
            {
                rightLever(2);
            }
            else if (state == 0)
            {
                rightLever(3);
            }
            else
            {
                rightLever(3);
            }
        }

        if (mode == llever_down)
        {
            if (state == 1)
            {
                leftLever(2);
            }
            else if (state == 0)
            {
                rightLever(3);
            }
            else
            {
                rightLever(3);
            }
        }

        if (mode == llever_up)
        {
            if (state == 1)
            {
                leftLever(1);
            }
            else if (state == 0)
            {
                rightLever(3);
            }
            else
            {
                rightLever(3);
            }
        }

        if (mode == door_up)
        {
            if (state == 1)
            {
                backDoor(1);
            }
            else if (state == 0)
            {
                backDoor(0);
            }
            else
            {
                backDoor(0);
            }
            
        }

        if (mode == door_down)
        {
            if (state == 1)
            {
                backDoor(2);
            }
            else if (state == 0)
            {
                backDoor(0);
            }
            else
            {
                backDoor(0);
            }
            
        }

        if (mode == trap_up)
        {
            if (state == 1)
            {
                trapDoor(1);
            }
            else if (state == 0)
            {
                trapDoor(0);
            }
            else
            {
                trapDoor(0);
            }
        }

        if (mode == trap_down)
        {
            if (state == 1)
            {
                trapDoor(2);
            }
            else if (state == 0)
            {
                trapDoor(0);
            }
            else
            {
                trapDoor(0);
            }
        }
    }
}
