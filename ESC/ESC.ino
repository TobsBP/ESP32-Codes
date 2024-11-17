#include <ESP32Servo.h>

Servo esc;                 // Create a Servo object
const int escPin = 18;     // Change this to the GPIO pin connected to the ESC signal
const int minPulseWidth = 1000; // Minimum pulse width (in microseconds)
const int maxPulseWidth = 2000; // Maximum pulse width (in microseconds)

void setup() {
  Serial.begin(115200);
  esc.attach(escPin, minPulseWidth, maxPulseWidth);
  Serial.println("Starting ESC test...");

  // Arming the ESC (sending minimum throttle)
  Serial.println("Arming ESC...");
  esc.writeMicroseconds(minPulseWidth);
  delay(2000);
  Serial.println("ESC armed. Ready for testing.");
}

void loop() {
  // Increase throttle gradually
  Serial.println("Increasing throttle...");
  for (int pulseWidth = minPulseWidth; pulseWidth <= maxPulseWidth; pulseWidth += 10) {
    esc.writeMicroseconds(pulseWidth);
    delay(100);
  }

  // Decrease throttle gradually
  Serial.println("Decreasing throttle...");
  for (int pulseWidth = maxPulseWidth; pulseWidth >= minPulseWidth; pulseWidth -= 10) {
    esc.writeMicroseconds(pulseWidth);
    delay(100);
  }
}
