#define relayPin 7

// Timing in milliseconds
const unsigned long dayOnTime = 1UL * 60UL * 1000UL;           // 1 min ON
const unsigned long dayOffTime = 10UL * 60UL * 1000UL;         // 10 min OFF

const unsigned long nightOnTime = 1UL * 60UL * 1000UL;         // 1 min ON
const unsigned long nightOffTime = 1UL * 60UL * 60UL * 1000UL; // 1 hour OFF

unsigned long previousMillis = 0;
bool pumpState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Start with pump OFF
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  // Day: 7 AM to 7 PM (first 12 hours)
  unsigned long dayDuration = 12UL * 60UL * 60UL * 1000UL; // 12 hrs
  unsigned long cycle24hr = 24UL * 60UL * 60UL * 1000UL;   // 24 hrs

  unsigned long elapsedTime = currentMillis % cycle24hr;
  bool isDay = elapsedTime < dayDuration;

  unsigned long onTime = isDay ? dayOnTime : nightOnTime;
  unsigned long offTime = isDay ? dayOffTime : nightOffTime;

  if (!pumpState) {
    if (currentMillis - previousMillis >= offTime) {
      pumpState = true;
      digitalWrite(relayPin, HIGH); // Turn ON pump
      previousMillis = currentMillis;
      Serial.println(isDay ? "DAY: Pump ON for 1 min" : "NIGHT: Pump ON for 1 min");
    }
  } else {
    if (currentMillis - previousMillis >= onTime) {
      pumpState = false;
      digitalWrite(relayPin, LOW); // Turn OFF pump
      previousMillis = currentMillis;
      Serial.println(isDay ? "DAY: Pump OFF for 10 min" : "NIGHT: Pump OFF for 1 hr");
    }
  }
}
