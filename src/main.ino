/*
* Bluetooh Basic: LED ON OFF - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* Download the App : https://github.com/Mayoogh/Arduino-Bluetooth-Basic
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/
String data; //Variable for storing received data
int movementVertical;
int movementHorizontal;
int movementRotation;
int lever;
int door;

void setup()
{
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
        data = Serial.readString(); //Read the incoming data & store into data
        Serial.println(data);   //Print Value inside data in Serial monitor
        // if (data == '1')
        // {                           // Checks whether value of data is equal to 1
        //     // digitalWrite(13, HIGH); //If value is 1 then LED turns ON
        //     analogWrite(12, 50);
        //     analogWrite(11, 50);
        //     analogWrite(10, 50);
        //     analogWrite(6, 50);
        //     analogWrite(5, 50);
        // }
        // else if (data == '0')
        // {                          //  Checks whether value of data is equal to 0
        //     // digitalWrite(13, LOW); //If value is 0 then LED turns OFF
        //     analogWrite(12, 0);
        //     analogWrite(11, 0);
        //     analogWrite(10, 0);
        //     analogWrite(6, 0);
        //     analogWrite(5, 0);
        // }
    }
}
