#include <Arduino.h>
#include "USB.h"
#include "USBHIDGamepad.h"

/*
 * WLED Arduino IDE compatibility file.
 * (this is the former wled00.ino)
 * 
 * Where has everything gone?
 * 
 * In April 2020, the project's structure underwent a major change.
 * We now use the platformIO build system, and building WLED in Arduino IDE is not supported any more.
 * Global variables are now found in file "wled.h"
 * Global function declarations are found in "fcn_declare.h"
 * 
 * Usermod compatibility: Existing wled06_usermod.ino mods should continue to work. Delete usermod.cpp.
 * New usermods should use usermod.cpp instead.
 */
#include "wled.h"

USBHIDGamepad Gamepad;

const char *productName = "FrontPanelMania";
const char *manufacturerName = "BillCo";

void setup() {
  for (byte currentPinIndex = 0; currentPinIndex < numOfButtons; currentPinIndex++) {
    pinMode(buttonPins[currentPinIndex], INPUT_PULLUP);
    previousButtonStates[currentPinIndex] = HIGH;
    currentButtonStates[currentPinIndex] = HIGH;
  }

  for (byte currentPinIndex = 0; currentPinIndex < numOfButtons; currentPinIndex++) {
    pinMode(LEDPins[currentPinIndex], OUTPUT);
    digitalWrite(LEDPins[currentPinIndex], HIGH);
    delay(200);
  }

  Gamepad.begin();
  USB.PID(0x0421);
  USB.VID(0x6970);
  USB.productName(productName);
  USB.manufacturerName(manufacturerName);
  USB.begin();
  WLED::instance().setup();
}

void loop() {
  WLED::instance().loop();
}
