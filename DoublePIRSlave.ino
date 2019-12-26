#include <SoftwareSerial.h>
#define LED1 11
#define LED2 12

SoftwareSerial BTSerial(0, 1); // RX, TX
long preTime1 = 0;
long preTime2 = 0;
long newDelay = 5000;
int flag1 = 0;
int flag2 = 0;
int LEDSTATE1 = LOW;
int LEDSTATE2 = LOW;
void setup() 
{
  Serial.begin(9600);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // set the data rate for the SoftwareSerial port
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  BTSerial.begin(9600);
}

void loop() 
{ // run over and over
  long current = millis();
  if(flag1 == 1)
  {
    if((current - preTime1 )>= newDelay) 
      {
        LEDSTATE1 = LOW;
        digitalWrite(LED1, LEDSTATE1);
        long t=current - preTime1;
        Serial.print("LED1 OFF: ");
        Serial.println(t);
        flag1 =0;
      }
  }
  if(flag2 == 1)
  {
    if((current - preTime2) >= newDelay) 
      {
        LEDSTATE2 = LOW;
        digitalWrite(LED2, LEDSTATE2);
        flag2 =0;
        long t=current - preTime2;
        Serial.print("LED2 OFF: ");
        Serial.println(t);
      }
  }
  
  if (BTSerial.available()) 
  {
    Serial.print("Signal 1: ");
    long time = millis();
    Serial.println(time);
    byte c = BTSerial.read();
    if(c == '1')
    {
      long now = millis();
      if(flag1 == 0)
      {
        flag1 = 1;
        LEDSTATE1 = HIGH;
        digitalWrite(LED1, LEDSTATE1);
        preTime1 =now;
      }
      
    }
    else if(c == '2')
    {
      Serial.print("Signal 2: ");
      long time = millis();
      Serial.println(time);
      if(flag2 == 0)
      {long now = millis();
        flag2 = 1;
        LEDSTATE2 = HIGH;
        digitalWrite(LED2, LEDSTATE2);
        preTime2 = now;
      }
    }
    BTSerial.flush();
  }
}
  
