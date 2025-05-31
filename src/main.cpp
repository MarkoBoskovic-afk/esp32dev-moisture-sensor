#include <Arduino.h>
int readMoistureRaw(int pin, int samples);
int mapToPercentage(int rawValue, int rawDry, int rawWet);

static const int MOISTURE_PIN = 34; 
static const int NUM_SAMPLES   = 20; 

static int rawDry = 3700; 
static int rawWet = 1600; 

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 Soil Moisture Sensor Reader");
  Serial.println("Calibrated rawDry  = " + String(rawDry));
  Serial.println("Calibrated rawWet  = " + String(rawWet));
  Serial.println("----------------------------------------");
}

void loop() {
  int rawValue = readMoistureRaw(MOISTURE_PIN, NUM_SAMPLES);

  float voltage = (rawValue / 4095.0f) * 3.3f;

  int moisturePct = mapToPercentage(rawValue, rawDry, rawWet);

  // 4) Print results
  Serial.print("Raw ADC: ");
  Serial.print(rawValue);
  Serial.print("    Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V    Moisture: ");
  Serial.print(moisturePct);
  Serial.println(" %");

  delay(1000);
}


int readMoistureRaw(int pin, int samples) {
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(10); // small delay to allow the ADC to settle
  }
  return static_cast<int>(sum / samples);
}

int mapToPercentage(int rawValue, int rawDry, int rawWet) {
  int percent = map(rawValue, rawDry, rawWet, 0, 100);
  percent = constrain(percent, 0, 100);
  return percent;
}
