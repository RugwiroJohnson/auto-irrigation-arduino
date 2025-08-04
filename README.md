# Auto Irrigation for hydroponics (Arduino)

This Arduino project controls a **water pump** using a **relay** based on simulated 24-hour day/night cycles — **no external timer or RTC** required.

## Day & Night Irrigation Cycles

- **Daytime (7 AM – 7 PM)**:
  - Pump ON: 2 minutes
  - Pump OFF: 1 minute

- **Nighttime (7 PM – 7 AM)**:
  - Pump ON: 2 hours
  - Pump OFF: 1 minute

The project uses `millis()` to track time internally and switches cycles based on elapsed time from power-up. A manual offset simulates starting at **7:00 AM**, even if powered on at a different time.

## Hardware Used
- Arduino Uno
- 1-channel Relay module
- Water pump (any low-voltage submersible pump)
- Jumper wires
- External power supply (for the pump and arduino when it is not connected to the computer)

## Key Features
- Fully **automatic timing control** without delay()
- Day/night cycle detection using internal time tracking
- Safe relay control (NO wiring: LOW = OFF, HIGH = ON)
- Serial monitoring output for debugging

## What I Learned
- How to simulate real-world time with `millis()`
- Relay control logic and safety considerations
- Implementing automated irrigation using code only

## How to Use
1. Connect the relay to pin 7
2. Wire the relay to your pump using the **Normally Open (NO)** configuration
3. Upload the code to the Arduino
4. Power it on at **7:18 PM** (or adjust the offset in `systemStartMillis`)
5. Monitor the Serial Monitor (optional) to see the ON/OFF cycle in real time

## Files Included
- `auto_irrigation_hydroponics.ino`: Main Arduino sketch

## Future Improvements
- Add RTC module (e.g., DS3231) for accurate real-time switching
