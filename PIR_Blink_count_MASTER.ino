#include<SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1); // RX, TX
int pir = 8;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.flush();
  Serial.println("Port connected!");
  pinMode(pir, INPUT);
  BTSerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int count = 0;
  while (1)
  {
    int val = digitalRead(pir);
    if (val == HIGH)
    {
      count ++;
      count = (count % 10);
      Serial.println(count);
      BTSerial.write(count);
     // blink(count);
    }
    delay(5200);
  }
}

void blink(int c)
{
  for (int i = 0; i <= c; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150);
    digitalWrite(LED_BUILTIN, LOW);
    delay(150);
  }
}
