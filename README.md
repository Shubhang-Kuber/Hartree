# Acoustic Energy Harvester 

## Introduction

This project is a proof-of-concept for harvesting ambient acoustic energy to power a smart electronic device. The system captures energy from sound vibrations using piezoelectric discs and uses it to power an Arduino-based circuit. This circuit monitors ambient light and automatically activates a bulb in the dark, demonstrating a practical use for harvested environmental energy.

---

## Project Overview

The system operates in several key stages:

-   **Energy Generation:** 5 piezoelectric discs are wired in parallel to convert sound vibrations into a small AC electrical signal.
-   **Power Conditioning:** A bridge rectifier converts AC to DC, a smoothing capacitor stabilizes the signal, and a DC-DC boost converter steps up the voltage to a stable 5V.
-   **Energy Storage:** A large electrolytic capacitor acts as a rechargeable reservoir to power the control circuit.
-   **Control & Sensing:** An Arduino UNO reads the ambient light level using a Light Dependent Resistor (LDR) connected to an analog pin.
-   **Load Switching:** A relay module, controlled by the Arduino, switches a separate, externally-powered circuit to turn the bulb on or off safely.

---

## Deliverables and Outcomes

-   **Hardware Prototype:** A fully assembled circuit that successfully harvests sound energy to power the control system.
-   **Control Software:** A clean, commented Arduino sketch (`.ino`) for sensing light and controlling the relay.
-   **Primary Outcome:** A functional, autonomous device that proves the viability of using acoustic energy to power a low-power "smart" application.

---

## Future Work 

Future enhancements could focus on three key areas:

-   **Efficiency Improvements:**
    -   Migrate from the Arduino UNO to a low-power microcontroller (e.g., ATtiny85, ESP32).
    -   Implement software deep-sleep modes to minimize standby power consumption.
-   **Harvesting Enhancement:**
    -   Design a resonant mounting structure for the piezo discs to mechanically amplify vibrations.
    -   Integrate a dedicated energy harvesting Power Management IC (PMIC) for more efficient conversion.
-   **Functionality Expansion:**
    -   Add data logging to an SD card to track energy generation over time.
    -   Incorporate a small LiPo battery and charge controller for more robust energy storage.
