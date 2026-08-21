# 🚦 Four-Way Traffic Light Control System

## 📌 Project Overview
This project is a complete hardware simulation and firmware implementation of a four-way traffic light control system. Built around the **PIC16F84A microcontroller**, it safely manages a standard intersection's traffic flow. The system includes an interactive standby mode and utilizes relays to isolate the low-voltage control logic from the high-voltage AC mains simulating the heavy-duty traffic lamps.

## ⚙️ Key Features
*   **State Machine Logic:** Cycles through a precision-timed 4-state traffic sequence (Red/Green/Yellow transitions).
*   **Non-Blocking Standby Control:** Features a push-button start/stop mechanism using edge-detection algorithms to prevent simulation latching and execution freezing.
*   **High-Voltage Isolation:** Uses 12V DC relays driven by 2N2222 NPN transistors to safely switch 325V Peak AC lamp circuits.
*   **Hardware Protection:** Incorporates 1N4007 flyback diodes to suppress inductive voltage spikes from the relay coils.
*   **Direct Bit-Level Mapping:** Firmware uses explicit bit-level pin assignments to prevent cross-contamination of microcontroller port registers.

## 🛠️ Technologies & Tools
*   **Microcontroller:** Microchip PIC16F84A (8MHz)
*   **Firmware/Language:** Embedded C (compiled via MikroC PRO for PIC)
*   **Simulation Environment:** Proteus Design Suite
*   **Power Regulation:** LM7805 Voltage Regulator (12V to 5V logic step-down)

## 🧰 Circuit Architecture
The Proteus schematic integrates the following subsystems:
1.  **MCU Core:** PIC16F84A with a 10k pull-down resistor on RA4 for the standby switch.
2.  **Relay Drivers:** 5V logic signals trigger the base of 2N2222 transistors, sinking current through the 12V relay coils.
3.  **Visual Indicators:** Low-power LEDs (Red, Yellow, Green) are wired in parallel with the relay coils for immediate logic-level status on the control board.
4.  **AC Load:** The relay contacts close the circuit for the 325V peak AC power source, driving the high-power traffic lamps.

## 🚀 Getting Started

### Prerequisites
*   **Proteus Design Suite** (v8.0 or higher recommended)
*   **MikroC PRO for PIC**

### Installation & Execution
1. ##Project demonstration
2. click here to watch the proteus simulation video[https://youtu.be/5l-kpTfBlr4?si=ZCGYdNp71yYcAZAB]
4.  Open the MikroC project file (`.mcppi`) to view or modify the C source code.
5.  Compile the code to generate the `traffic.hex` file.
6.  Open the Proteus simulation file (`.pdsprj`).
7.  Double-click the PIC16F84A component in Proteus:
    *   Set the **Processor Clock Frequency** to `8MHz`.
    *   Link the **Program File** to the newly generated `traffic.hex`.
8.  Run the simulation and press the Start/Stop button connected to RA4 to initiate the intersection sequence.

## 🧠 Engineering Challenges Solved
*   **Flyback Diode Polarity:** Resolved relay failure by correcting flyback diode orientation, preventing forward-biased short circuits to ground when the transistor driver activated.
*   **Switch Latching & Debounce:** Replaced standard blocking delay loops (`while(PORTA.F4 == 1)`) with a custom polling delay and `button_prev` state memory. This prevents the microcontroller from freezing if the button is latched in the simulation environment, ensuring immediate sequence abortion when requested.

## 👨‍💻 Author
*r70879969(RAFI OUMAR)
*B.Eng. Electrical and Electronic Engineering*

---
*If you find this project helpful, feel free to leave a ⭐!*
