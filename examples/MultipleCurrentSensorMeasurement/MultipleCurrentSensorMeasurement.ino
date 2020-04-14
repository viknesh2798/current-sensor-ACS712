#include "ACS712.h"

// We have 30 amps version sensor connected to A0 and A1 pin of arduino
// Replace with your version if necessary
ACS712 sensor1(ACS712_30A, A0);
ACS712 sensor2(ACS712_30A, A1);

void setup() {
  Serial.begin(9600);

  // This method calibrates zero point of each sensor,
  // It is not necessary, but may positively affect the accuracy
  // Ensure that no current flows through the sensor at this moment
  sensor1.calibrate();
  sensor2.calibrate();
}

void loop() {
  
  // To measure current we need to know the frequency of current.
  // By default 50Hz is used, but you can specify own, if necessary
  float i1 = sensor1.getCurrentAC();
  float i2 = sensor2.getCurrentAC();
  
  // The current through each current sensor is printed 
  // every 1 sec in the Serial monitor
  Serial.println(String("I1 = ") + i1 + " A" + "\tI2 = " + i2 + " A");
  delay(1000); 
}
