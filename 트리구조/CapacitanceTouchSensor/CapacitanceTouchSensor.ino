#include <CapacitiveSensor.h>
CapacitiveSensor cs_2_5=CapacitiveSensor(2,5);

void setup() {
 Serial.begin(9600);
 

}

void loop() {
  double SEN=cs_2_5.capacitiveSensor(30);
  Serial.println(SEN);
  delay(50);
}
