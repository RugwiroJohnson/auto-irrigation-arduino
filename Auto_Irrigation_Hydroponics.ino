#define relayPin 7

// Timing in milliseconds
const unsigned long dayOnTime = 20UL * 60UL * 1000UL;      // 2 min ON
const unsigned long dayOffTime = 1UL * 60UL * 1000UL;    // 20 min OFF

const unsigned long nightOnTime = 2UL * 60UL * 60UL * 1000UL;        // 2 min ON
const unsigned long nightOffTime = 1UL * 60UL * 1000UL; // 2 hr OFF

unsigned long systemStartMillis = 0;
unsigned long previousMillis = 0;
bool pumpState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure pump OFF initially
  Serial.begin(9600);
  
  // Manual offset to align 7:00 AM reference while powering ON at 7:18 PM
  systemStartMillis = millis() - 44280000UL; // 12 hr 18 min offset
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long elapsedTime = currentMillis - systemStartMillis;

  // Day = 12 hr (7 AM - 7 PM), Night = 12 hr (7 PM - 7 AM)
  unsigned long cycle24hr = 24UL * 60UL * 60UL * 1000UL; // 24 hr in ms
  unsigned long dayDuration = 12UL * 60UL * 60UL * 1000UL; // 12 hr in ms

  bool isDay = (elapsedTime % cycle24hr) < dayDuration;

  unsigned long onTime = isDay ? dayOnTime : nightOnTime;
  unsigned long offTime = isDay ? dayOffTime : nightOffTime;

  if (!pumpState) { // Pump is OFF
    if (currentMillis - previousMillis >= offTime) {
      pumpState = true;
      digitalWrite(relayPin, HIGH); // HIGH = ON for NO relay wiring
      previousMillis = currentMillis;
      Serial.println(isDay ? "DAY: Pump ON 2 min" : "NIGHT: Pump ON 2 min");
    }
  } else { // Pump is ON
    if (currentMillis - previousMillis >= onTime) {
      pumpState = false;
      digitalWrite(relayPin, LOW); // LOW = OFF for NO relay wiring
      previousMillis = currentMillis;
      Serial.println(isDay ? "DAY: Pump OFF 20 min" : "NIGHT: Pump OFF 2 hr");
    }
  }
}