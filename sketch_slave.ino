#include <SoftwareSerial.h>
#define led 12

SoftwareSerial BTSerial(0, 1); // RX, TX

void setup() 
{
  Serial.begin(9600);
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.flush();
  // set the data rate for the SoftwareSerial port
  pinMode(led, OUTPUT);
  BTSerial.begin(9600);
  BTSerial.setTimeout(100);
}

void loop() 
{ // run over and over
  if (BTSerial.available()) 
  {
    int c = BTSerial.read() - '0';
    Serial.println(c);
    if(c>=0 & c<20 )
    {
      blink(c);
    }
  }
}
  
void blink(int c)
{
  
  for(int i = 0;i<=c;i++)
  {
    digitalWrite(led,HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(150);
  }
}
