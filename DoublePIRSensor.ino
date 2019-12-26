#include <SoftwareSerial.h>
#define pir1 7
#define pir2 8

SoftwareSerial BTSerial(0, 1); // RX, TX

int val1 = 0;
int val2 = 0;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val1 = digitalRead(pir1);
  int val2 = digitalRead(pir2);
  if(val1 == HIGH)
  {
    char one = '1';
    BTSerial.write(one);
    val1 = LOW;
  }
  if(val2 == HIGH)
  {
    char two = '2';
    BTSerial.write(two);
    val2 = LOW;
  }
  delay(2500);
}
