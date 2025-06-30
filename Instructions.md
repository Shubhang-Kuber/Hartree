### **A Quick Word on Safety**

*   **ELECTRICAL CONNECTIONS:** Always double-check your wiring before applying power. Incorrect connections can damage components or cause short circuits.
*   **SOLDERING:** Use proper ventilation when soldering and handle the iron with care to avoid burns.
*   **EXTERNAL POWER:** When connecting the bulb circuit, use only low voltage power sources to avoid electrical hazards.

---

### **Part 1: Understanding Your Components**

Before we start building, let's understand what each component does in your energy harvesting system.

*   **Piezoelectric Discs (x5):** These are your energy generators. When they vibrate or experience mechanical stress (like sound waves), they produce small amounts of electrical energy. We'll connect them in parallel to increase current output.

*   **Bridge Rectifier:** Piezoelectric discs produce AC (alternating current) electricity, but most electronics need DC (direct current). This component converts the AC from your piezo array into usable DC power.

*   **Capacitors (x2):** These act as temporary energy storage and voltage smoothing devices. The first smaller capacitor (100µF) smooths the pulsating DC from the rectifier. The second larger capacitor (1000µF+) acts as your main energy reservoir.

*   **Voltage Module (DC-DC Boost Converter):** The voltage from piezoelectric discs is often very low (under 1V). This module "boosts" that low voltage up to a stable 5V that can power your Arduino and other components.

*   **Arduino UNO:** This is the brain of your system. It reads the light sensor and controls when the bulb turns on or off based on ambient light conditions.

*   **LDR (Light Dependent Resistor):** Your light sensor. Its resistance changes based on how much light hits it - high resistance in darkness, low resistance in bright light.

*   **Relay Module:** This acts as an electronically controlled switch. The Arduino sends a signal to the relay, which then switches the separate bulb circuit on or off. This allows low-power Arduino signals to control higher-power devices safely.

*   **Bulb:** Your load device that demonstrates the system working. When it's dark, the harvested energy powers this bulb automatically.

---

### **Part 3: Wiring Everything Together**

Follow these connections step by step. Take your time and double-check each connection.

**Step A: Building the Piezoelectric Energy Harvester**

1. **Assemble the Piezo Array:**
  - Solder all 5 red wires from the piezoelectric discs together into one positive lead
  - Solder all 5 black wires together into one negative lead
  - This parallel connection increases your current output

2. **Connect the Bridge Rectifier:**
  - Connect the combined positive (red) lead from piezo array to one AC input (~) on the rectifier
  - Connect the combined negative (black) lead to the other AC input (~) on the rectifier

3. **Add the First Smoothing Capacitor:**
  - Connect the positive leg of your smaller capacitor (100µF) to the rectifier's positive (+) output
  - Connect the negative leg to the rectifier's negative (-) output

**Step B: Power Conditioning and Storage**

4. **Connect the Voltage Boost Module:**
  - Connect the positive output from the smoothing capacitor to the boost module's 'IN+' or 'VIN+' terminal
  - Connect the negative output to the boost module's 'IN-' or 'GND' input terminal
  - Adjust the boost module output to 5V using its potentiometer (if adjustable)

5. **Add the Storage Capacitor:**
  - Connect the positive leg of your larger capacitor (1000µF+) to the boost module's 'OUT+' or 'VOUT+' terminal
  - Connect the negative leg to the boost module's 'OUT-' or 'GND' output terminal

**Step C: Arduino and Sensor Connections**

6. **Power the Arduino:**
  - Connect the positive output from your storage capacitor to the Arduino's 'Vin' pin
  - Connect the negative output to the Arduino's 'GND' pin

7. **Wire the LDR Sensor (Voltage Divider Circuit):**
  - Connect Arduino '5V' pin to one leg of the LDR
  - Connect the other leg of the LDR to both:
    - Arduino Analog Pin 'A0'
    - One leg of a 10kΩ resistor
  - Connect the other leg of the 10kΩ resistor to Arduino 'GND'

**Step D: Relay and Load Circuit**

8. **Connect the Relay Module:**
  - Connect relay 'VCC' pin to Arduino '5V' pin
  - Connect relay 'GND' pin to Arduino 'GND' pin
  - Connect relay 'IN' (or 'SIG') pin to Arduino Digital Pin 7

9. **Wire the Bulb Load Circuit:**
  - Connect external power source positive to relay 'COM' (Common) terminal
  - Connect a wire from relay 'NO' (Normally Open) terminal to one contact of the bulb
  - Connect the other bulb contact to external power source negative

---

### **Part 5: Physical Assembly**

Now let's put everything together in a practical, functional layout.

1. **Component Mounting:**
  - Mount all electronic components on a project board or inside a protective enclosure
  - Ensure the piezoelectric discs are exposed and can vibrate freely - they need to capture sound/vibration energy
  - Position the LDR sensor where it can accurately detect ambient light levels

2. **Energy Harvesting Setup:**
  - Place the piezoelectric discs near a continuous sound source (speaker, radio, or area with ambient noise)
  - The discs should be free to vibrate - don't mount them too rigidly
  - Consider mounting them on a resonant surface to amplify vibrations

3. **Secure All Connections:**
  - Double-check all soldered joints are solid
  - Ensure no loose wires that could cause short circuits
  - Use cable ties or electrical tape to organize wiring neatly

---

### **Part 6: Uploading the Code**

Program your Arduino to control the automatic lighting system.

1. **Connect to Computer:**
  - Connect your Arduino to your computer using a USB cable
  - Open the Arduino IDE software

2. **Configure the IDE:**
  - Go to **Tools → Board** and select **"Arduino Uno"**
  - Go to **Tools → Port** and select your Arduino's port

3. **Upload the Control Code:**

---

### **Part 7: Power On and Operation!**

1. Disconnect USB: Remove the USB cable from the Arduino.I
- It will now run on harvested energy.
- Start Energy Harvesting.

3. Position your piezoelectric discs near a sound source (music, conversation, ambient noise)
- Allow several minutes for energy to accumulate in your storage capacitor
- The system needs time to build up enough charge to operate


3. Monitor the System:
- Watch the storage capacitor voltage if you have a multimeter
- You should see voltage gradually building up to around 5V

---

  ### **What to Expect:**
1. Initial Charging Phase:
- The system will take 5-15 minutes to accumulate enough energy to start operating
- During this time, the Arduino may not have enough power to run consistently


2. Automatic Operation:

- Once sufficient energy is stored, the Arduino will begin monitoring light levels every second
- In bright conditions: The bulb remains OFF, conserving harvested energy
- In dark conditions: The relay clicks and the bulb turns ON automatically


3. Energy Management:

- The system will only operate when there's enough harvested energy
- If energy runs low, the Arduino may stop functioning until more energy is collected
- Continuous sound/vibration input will keep the system running longer


4. Testing the System:

-Cover the LDR sensor with your hand to simulate darkness - the bulb should turn on
- Uncover the LDR sensor - the bulb should turn off after about 1 second
- The relay will make a clicking sound each time it switches
