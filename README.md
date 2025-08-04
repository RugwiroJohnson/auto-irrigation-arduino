# Auto Irrigation for Hydroponics (Arduino)

This Arduino project controls a **water pump** using a **relay** based on a simulated 24-hour day/night cycle - **no external timer or RTC required**.

## Day & Night Irrigation Cycles

- **Daytime (7 AM - 7 PM)**:
  - Pump ON: 2 minutes
  - Pump OFF: 1 minute

- **Nighttime (7 PM - 7 AM)**:
  - Pump ON: 2 hours
  - Pump OFF: 1 minute

The project uses `millis()` to track time internally and automatically switches cycles based on elapsed time from startup. **Just power the Arduino at exactly 7:00 AM**, and the logic will take care of the rest.

## Hardware Used

- Arduino Uno
- 1-channel Relay Module
- Submersible water pump (low-voltage)
- Jumper wires
- External power supply (for Arduino and pump)

## Key Features

- Fully **automatic irrigation control**
- No use of `delay()` - non-blocking logic with `millis()`
- **Day/night cycle simulation** without RTC or external timer
- Safe relay control (Normally Open wiring: LOW = OFF, HIGH = ON)
- Serial output for real-time monitoring

## How to Use

1. Connect the relay to pin **7**
2. Wire the relay to the pump using the **Normally Open (NO)** configuration
3. Upload the code to your Arduino
4. Power on the Arduino at **exactly 7:00 AM**
5. Monitor the Serial Monitor (optional) for ON/OFF logs

## Files Included

- `auto_irrigation_hydroponics.ino`: Main Arduino sketch

## What I Learned

- Simulating time-based logic using `millis()`
- Safe relay control principles
- Creating an automated irrigation system without delays or RTCs

## Future Improvements

- Add an **RTC module** for more robust real-time tracking
- Add soil moisture or temperature sensors for smart irrigation
- Create a web dashboard or SMS alert system
