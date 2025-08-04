#define relayPin 7

// Timing in milliseconds
const unsigned long dayOnTime = 2UL * 60UL * 1000UL;      // 2 minutes ON
const unsigned long dayOffTime = 1UL * 60UL * 1000UL;     // 1 minute OFF

const unsigned long nightOnTime = 2UL * 60UL * 60UL * 1000UL;  // 2 hours ON
const unsigned long nightOffTime = 1UL * 60UL * 1000UL;        // 1 minute OFF

unsigned long systemStartMillis = 0;
unsigned long previousMillis = 0;
bool pumpState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure pump is OFF initially
  Serial.begin(9600);

  // No offset — Arduino powered on exactly at 7:00 AM
  systemStartMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long elapsedTime = currentMillis - systemStartMillis;

  // Define 24hr cycle: Day = 7 AM to 7 PM, Night = 7 PM to 7 AM
  unsigned long cycle24hr = 24UL * 60UL * 60UL * 1000UL; // 24 hours in ms
  unsigned long dayDuration = 12UL * 60UL * 60UL * 1000UL; // 12 hours in ms

  bool isDay = (elapsedTime % cycle24hr) < dayDuration;

  unsigned long onTime = isDay ? dayOnTime : nightOnTime;
  unsigned long offTime = isDay ? dayOffTime : nightOffTime;

  if (!pumpState) { // Pump is OFF
    if (currentMillis - previousMillis >= offTime) {
      pumpState = true;
      digitalWrite(relayPin, HIGH); // Turn pump ON
      previousMillis = currentMillis;
      Serial.println(isDay ? "DAY: Pump ON (2 min)" : "NIGHT: Pump ON (2 hrs)");
    }
  } else { // Pump is ON
    if (currentMillis - previousMillis >= onTime) {
      pumpState = false;
      digitalWrite(relayPin, LOW); // Turn pump OFF
      previousMillis = currentMillis;
      Serial.println(isDay ? "DAY: Pump OFF (1 min)" : "NIGHT: Pump OFF (1 min)");
    }
  }
}
