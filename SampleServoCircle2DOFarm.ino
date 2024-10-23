#include <Servo.h>
Servo myservo1, myservo2;
#define PWMMIN (834)
#define PWMMAX (2168)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myservo1.attach( 9, PWMMIN, PWMMAX);
  myservo2.attach(10, PWMMIN, PWMMAX);
  myservo1.write(90);
  myservo2.write(90);
  delay(1000);
}

long TMAX=(50);
#define RAD2DEG(RAD)  (180*RAD/PI)

#define L1  (80)  // Length of the link1 [mm]
#define L2  (60)  // Length of the link2 [mm]
#define XC  (110) // Center of the circle [mm]
#define YC  (0)   // Center of the circle [mm]
#define R   (15)  // Radius of the circle [mm]

#define THETA2SERVO(theta) ((theta)+90) // from theta to servo command angle

void loop() {
  float rad, xe, ye, theta1, theta2;
  int theta1deg, theta2deg;
  Serial.println("Begin:");
  // degmin ~ degmid (y=a*t^2)
  for (int t = 0; t < TMAX; t++) {
    rad = (2*PI) * t / TMAX;
    xe = XC + R * cos(rad);
    ye = YC + R * sin(rad);
    theta1=calc_theta1(xe, ye);
    theta2=calc_theta2(xe, ye);
    theta1deg=RAD2DEG(theta1); theta2deg=RAD2DEG(theta2);
//    myservo1.write(THETA2SERVO(theta1deg));
//    myservo2.write(THETA2SERVO(theta2deg));
    Serial.print(theta1deg); Serial.print(", "); Serial.println(theta2deg);
    delay(20);
  }
  Serial.println("End");
}

float calc_theta1 (float xe, float ye) {
  float theta1;
  // calculating theta1 using xe and ye
  return theta1;
}

float calc_theta2 (float xe, float ye) {
  float theta2;
  // calculating theta2 using xe and ye
  return theta2;
}
