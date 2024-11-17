#include <Arduino.h>

const int s0 = 14;  // Pin S0
const int s1 = 27;  // Pin S1
const int s2 = 26;  // Pin S2
const int s3 = 25;  // Pin S3
const int outPin = 34; // Output pin (OUT)

void setup() {
  Serial.begin(115200);

  // Set the S0, S1, S2, and S3 pins as outputs
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT);

  // Set the frequency scaling to 20%
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

void loop() {
  int red, green, blue;

  // Read red color
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(outPin, LOW);

  // Read green color
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  green = pulseIn(outPin, LOW);

  // Read blue color
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  blue = pulseIn(outPin, LOW);

  // Print the values to the Serial Monitor
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.println(blue);

  delay(500);
}
