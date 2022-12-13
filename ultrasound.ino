#include <Ultrasonic.h>
#define button 7 //push button pin


float dist = 0; //distance measured by ultrosnc
int haptic = 10;//haptic motor pin
int loudness;//how loud the vibration is
int pushbtn = 1;//state of the push button
Ultrasonic ultrasonic(12,13);

void setup() 
{
  Serial.begin(9600);
  pinMode(haptic , OUTPUT);
  pinMode(button , INPUT_PULLUP);

}

void loop()
{
  // put your main code here, to run repeatedly:
  dist = ultrasonic.read();
  Serial.println(dist);
  if (digitalRead(button) == 0) //if the push button is pressed
  {
    Serial.print("BUTTON SWITCHED");

    delay(2000); //
    if (pushbtn == 0)
    {
      pushbtn = 1; //condition of the pushbtn is set to high
    }
    else
    {
      pushbtn = 0;      //else is set to to low
    }
  }

  else //
  {
  if (pushbtn == 0)
  {
    dist = ultrasonic.read();
    loudness = 255.0 - (dist/357.0 *255.0);
    analogWrite(haptic , loudness);
    Serial.println(loudness);    
  }
  else
  {
    analogWrite(haptic , 0);    
  }
  } 
}