#include <Strain.h>
#include <Servo.h>

Strain gauge(32, 0x0);
Servo servo;

void setup() {
  // put your setup code here, to run once:

  gauge.attach(1);
  servo.attach(3);

  servo.write(5);

  delay(2000);
  Serial.begin(115200);
  
}

int count;
void loop() {
  // put your main code here, to run repeatedly:

  servo.write(5);

  gauge.nextSample();

  if(count % 32 == 0)
  {
  Serial.print(gauge.read(), DEC);
  Serial.print(" grams ");
//  Serial.print(gauge.mean, DEC);
//  Serial.print(" mu ");
  Serial.println(sqrt(gauge.variance), DEC);
  }
  ++count;

  if(Serial.available() > 0)
  {
    char c;
    while(Serial.available() > 0) 
      c = Serial.read();

    switch(c)
    {
      case 'c':
        gauge.calibrate(0x0);
        break;        
    }
  }

  delay(1);
}

