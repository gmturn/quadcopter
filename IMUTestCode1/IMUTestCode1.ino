#include <Wire.h>

#define Gyro_gX0 0x28
#define Gyro_gX1 0x29
#define Gyro_gY0 0x2A
#define Gyro_gY1 0x2B
#define Gyro_gZ0 0x2C
#define Gyro_gZ1 0x2D

int Gyro = 0x69;  // device address

int gX0, gX1, gX_out;
int gY0, gY1, gY_out;
int gZ0, gZ1, gZ_out;
float Xg, Yg, Zg;
float angleX, angleY, angleZ, angleXc, angleYc, angleZc;

unsigned long start, finished, elapsed;
float dt = 0.015;


void setup() {
  int Gyro = 0x69;  // device address

  int gX0, gX1, gX_out;
  int gY0, gY1, gY_out;
  int gZ0, gZ1, gZ_out;
  float Xg, Yg, Zg;
  float angleX, angleY, angleZ, angleXc, angleYc, angleZc;

  unsigned long start, finished, elapsed;
  float dt = 0.015;
  
  Wire.begin();
  Serial.begin(9600);
  delay(100);

  Wire.beginTransmission(Gyro);
  Wire.write(0x20);  // CTRL_REG - Power Mode
  Wire.write(15);  // 2000dps (degrees per second): 48d - 00110000b
  Wire.endTransmission();


}

void loop() {
  int Gyro = 0x69;  // device address


  int gX0, gX1, gX_out;
  int gY0, gY1, gY_out;
  int gZ0, gZ1, gZ_out;
  float Xg, Yg, Zg;
  float angleX, angleY, angleZ, angleXc, angleYc, angleZc;

  unsigned long start, finished, elapsedTime;
  float dt = 0.015;
  
  
  
  start = millis();
  
  //----X-Axis
  // X0
  Wire.beginTransmission(Gyro);  // transmit to device
  Wire.write(Gyro_gX0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1); 
  if (Wire.available() <= 1) {
    gX0 = Wire.read();
  }
  
  // X1  
  Wire.beginTransmission(Gyro);  // transmit to device
  Wire.write(Gyro_gX1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1);
  if (Wire.available() <= 1) {
    gX1 = Wire.read();
  }


  //---- Y-Axis
  // Y0
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gY0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1); 
  if (Wire.available() <= 1) {
    gY0 = Wire.read();
  }

  // Y1
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gY1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1); 
  if (Wire.available() <= 1) {
    gY1 = Wire.read();
  }


  //---- Z-Axis
  // Z0  
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gZ0);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1); 
  if (Wire.available() <= 1) {
    gZ0 = Wire.read();
  }

  // Z1
  Wire.beginTransmission(Gyro);
  Wire.write(Gyro_gZ1);
  Wire.endTransmission();
  Wire.requestFrom(Gyro, 1); 
  if (Wire.available() <= 1) {
    gZ1 = Wire.read();
  }  




  // X-AXIS RAW DATA
  gX1 = gX1 << 8;
  gX_out = gX0 + gX1;

  // From datasheet: 70 mdps/digit
  Xg = gX_out * 0.0;  // angle = dt * angular rate

  angleXc = Xg * dt;
  angleX = angleX + angleXc;


  // Y-AXIS RAW DATA
  gY1 = gY1 << 8;
  gY_out = gY0 + gY1;
  Yg = gY_out * 0.07;
  angleYc = Yg * dt;
  angleY = angleY + angleYc;


  // Z-AXIS RAW DATA
  gZ1 = gZ1 << 8;  
  gZ_out = gZ0 + gZ1;
  Zg = gZ_out * 0.07;
  angleZc = Zg * dt;
  angleZ = angleZ + angleZc;


  // PRINTING DATA TO SERIAL MONITOR
  Serial.print("Angle X= ");
  Serial.print(angleX);
  Serial.print("\tAngle Y= ");
  Serial.print(angleY);
  Serial.print("\tAngle Z= ");
  Serial.print(angleZ);
  Serial.print("\n");

  
  delay(10);
  
  // Calculating dt
  finished = millis();
  elapsedTime = finished - start;
  dt = elapsedTime / 1000.0;
  start = 0;
  elapsedTime = 0;
  
}

























