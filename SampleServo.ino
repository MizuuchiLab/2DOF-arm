#include <Servo.h>
Servo myservo1, myservo2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myservo1.attach( 9, 920, 2120);
  myservo2.attach(10, 920, 2120);
  myservo1.write(90);
  myservo2.write(90);
  delay(1000);
}

long TMAX=(50);

void loop() {
  int theta1deg, theta2deg;
  // put your main code here, to run repeatedly:
  for (int t = 0; t < TMAX; t++) {
    theta1deg = -45 + 90 * t/TMAX;
    theta2deg =  45 - 90 * t/TMAX;
    myservo1.write(theta1deg));
    myservo2.write(theta2deg);
    Serial.print(theta1deg); Serial.print(", "); Serial.println(theta2deg);
    delay(100);
  }
}
