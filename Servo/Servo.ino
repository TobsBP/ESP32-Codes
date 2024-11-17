#include <ESP32Servo.h>

Servo esc;
int escPin = 18;

void setup() {
  esc.attach(escPin);  // Anexa o ESC ao pino definido
  Serial.begin(115200);
}

void loop() {
  esc.write(110);
}