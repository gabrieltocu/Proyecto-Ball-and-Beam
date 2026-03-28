#include <Dynamixel2Arduino.h>

#define DXL_SERIAL   Serial1
#define DEBUG_SERIAL Serial
#define DXL_DIR_PIN  28
#define SERVO_ID     1
#define BAUDRATE     1000000

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

using namespace ControlTableItem;

void setup() {
  DEBUG_SERIAL.begin(9600);
  dxl.begin(BAUDRATE);
  dxl.setPortProtocolVersion(1.0);

  if (dxl.ping(SERVO_ID)) {
    DEBUG_SERIAL.println("Servo found!");
  } else {
    DEBUG_SERIAL.println("Servo not found. Check wiring and power.");
  }

  dxl.torqueOff(SERVO_ID);
  dxl.setOperatingMode(SERVO_ID, OP_POSITION);
  dxl.torqueOn(SERVO_ID);

  DEBUG_SERIAL.println("AX-12A ready");
}

void loop() {
  dxl.setGoalPosition(SERVO_ID, 700);   // right
  delay(2000);
  dxl.setGoalPosition(SERVO_ID, 512);   // center
  delay(2000);
  dxl.setGoalPosition(SERVO_ID, 300);   // left
  delay(2000);
}