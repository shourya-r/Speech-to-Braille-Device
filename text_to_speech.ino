#include <Servo.h>

// Creating an array for the LEDs, indicating to which pins they are connected
int led[] = {2, 4, 7, 8, 12, 13};

char readCharacter; // Variable that will store the character entered by the user
bool dots[6]; // Array that will indicate which dots should be lit

int servoPosition[] = {0, 1, 2, 3, 4, 5};
int motorPin[6] = {3, 5, 6, 9, 10, 11};
Servo motor[6];

void setup()
{
  Serial.begin(9600); // Starts serial communication
  int i; // Loop control variable
  for (i = 0; i < 6; i++)
  {
    pinMode(led[i], OUTPUT); // Defines LED pins as output
    motor[i].attach(motorPin[i]);
    motor[i].write(0); // Initializes motor at position zero
  }
}

void loop()
{
  if (Serial.available())
  { // To read when the user enters something
    readCharacter = Serial.read(); // Reads the character entered by the user and stores it in the variable
    updateDots(readCharacter); // Calls the function that updates the dots array according to the entered character
    int i; // Loop control variable
    for (i = 0; i < 6; i++)
    {
      digitalWrite(led[i], dots[i]); // Turns on or off LEDs according to the dots array
    }
    moveMotor();
    delay(500); // Time with the LEDs on
    for (i = 0; i < 6; i++)
    {
      digitalWrite(led[i], LOW); // Turns off all LEDs
    }
    delay(500); // Wait time with the LEDs off
  }
}

void moveMotor()
{
  int i;
  for (i = 0; i < 6; i++)
  {
    if (dots[i] == HIGH)
    {
      for (servoPosition[i] = 0; servoPosition[i] < 45; servoPosition[i]++)
      {
        motor[i].write(servoPosition[i]);
        delay(15);
      }
      delay(200);
      for (servoPosition[i] = 45; servoPosition[i] >= 0; servoPosition[i]--)
      {
        motor[i].write(servoPosition[i]);
        delay(15);
      }
    }
  }
}

// Function that updates the dots array, indicating which dots should be lit
char updateDots(char character)
{
  int i; // Loop control variable
  for (i = 0; i < 6; i++)
  {
    dots[i] = LOW;
  }
  switch (character)
  {
  case 'a':
    dots[0] = HIGH;
    break;

  case 'b':
    dots[0] = HIGH;
    dots[2] = HIGH;
    break;

  case 'c':
    dots[0] = HIGH;
    dots[1] = HIGH;
    break;

  case 'd':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[3] = HIGH;
    break;

  case 'e':
    dots[0] = HIGH;
    dots[3] = HIGH;
    break;

  case 'f':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[2] = HIGH;
    break;

  case 'g':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    break;

  case 'h':
    dots[0] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    break;

  case 'i':
    dots[1] = HIGH;
    dots[2] = HIGH;
    break;

  case 'j':
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    break;

  case 'k':
    dots[0] = HIGH;
    dots[4] = HIGH;
    break;

  case 'l':
    dots[0] = HIGH;
    dots[2] = HIGH;
    dots[4] = HIGH;
    break;

  case 'm':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[4] = HIGH;
    break;

  case 'n':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[3] = HIGH;
    dots[4] = HIGH;
    break;

  case 'o':
    dots[0] = HIGH;
    dots[3] = HIGH;
    dots[4] = HIGH;
    break;

  case 'p':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[4] = HIGH;
    break;

  case 'q':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    dots[4] = HIGH;
    break;

  case 'r':
    dots[0] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    dots[4] = HIGH;
    break;

  case 's':
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[4] = HIGH;
    break;

  case 't':
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    dots[4] = HIGH;
    break;

  case 'u':
    dots[0] = HIGH;
    dots[4] = HIGH;
    dots[5] = HIGH;
    break;

  case 'v':
    dots[0] = HIGH;
    dots[2] = HIGH;
    dots[4] = HIGH;
    dots[5] = HIGH;
    break;

  case 'w':
    dots[1] = HIGH;
    dots[2] = HIGH;
    dots[3] = HIGH;
    dots[5] = HIGH;
    break;

  case 'x':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[4] = HIGH;
    dots[5] = HIGH;
    break;

  case 'y':
    dots[0] = HIGH;
    dots[1] = HIGH;
    dots[3] = HIGH;
    dots[4] = HIGH;
    dots[5] = HIGH;
    break;

  case 'z':
    dots[0] = HIGH;
    dots[3] = HIGH;
   	dots[4] = HIGH;
    dots[5] = HIGH;
    break;
  }
} 
