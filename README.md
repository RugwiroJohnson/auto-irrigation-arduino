# Auto Irrigation for Hydroponics (Arduino)

This Arduino project controls a **water pump** using a **relay** based on a simulated 24-hour day/night cycle - **no external timer or RTC required**.

## Day & Night Irrigation Cycles

- **Daytime (7 AM - 7 PM)**:
  - Pump ON: **1 minute**
  - Pump OFF: **10 minutes**

- **Nighttime (7 PM - 7 AM)**:
  - Pump ON: **1 minute**
  - Pump OFF: **1 hour**

The project uses `millis()` to track time internally and automatically switches cycles based on time elapsed since startup.  
**Just power the Arduino at exactly 7:00 AM**, and the logic handles the rest.

## Hardware Used

- Arduino Uno  
- 1-channel Relay Module  
- Submersible water pump (low-voltage)  
- Jumper wires  
- External power supply (for Arduino and pump)

## Key Features

- Fully **automatic irrigation control**  
- Non-blocking logic using `millis()` (no `delay()`)  
- **Day/night simulation** without RTC or external timer  
- Safe relay control (LOW = OFF, HIGH = ON)  
- Serial logs for real-time status updates

## How to Use

1. Connect the relay control pin to **pin 7** on the Arduino  
2. Use the **Normally Open (NO)** configuration on the relay  
3. Upload the code to your Arduino board  
4. Power on the Arduino at **exactly 7:00 AM**  
5. Open the Serial Monitor to view irrigation logs (optional)

## What I Learned

- Simulating time-based logic using `millis()`  
- Non-blocking control for real-time automation  
- Safe and simple relay control  
- How to build an irrigation system without delays, RTCs, or complex sensors

