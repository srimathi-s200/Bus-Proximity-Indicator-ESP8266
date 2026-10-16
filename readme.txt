🚌 Bus Proximity Indicator Using ESP8266

📌 Project Overview

The Bus Proximity Indicator is an embedded systems project designed to demonstrate how wireless communication can be used to indicate the proximity of a bus to a bus stop.

The prototype uses two NodeMCU ESP8266 development boards to establish Wi-Fi communication. The transmitter sends data to the receiver using the User Datagram Protocol (UDP). The receiver monitors the received signal strength indicator (RSSI) and uses a threshold-based decision to control an LED as a proximity indicator.

This project demonstrates the practical application of embedded systems, wireless networking, and real-time status indication.

🎯 Objectives

- Develop wireless communication between two ESP8266 boards.
- Implement data transmission using Wi-Fi and UDP.
- Explore RSSI-based proximity indication.
- Control an LED based on a received signal-strength threshold.
- Understand communication between embedded devices.

🧰 Components Required

S. No.| Component| Quantity
1| NodeMCU ESP8266 development board| 2
2| LED| 1
3| 220 Ω resistor| 1
4| Breadboard and jumper wires| As required
5| USB cables for programming and power| 2
6| Computer with Arduino IDE| 1

⚙️ Technologies Used

- Microcontroller: ESP8266 NodeMCU
- Programming language: Embedded C/C++ using Arduino IDE
- Wireless communication: Wi-Fi
- Communication protocol: UDP (User Datagram Protocol)
- Proximity estimation: RSSI (Received Signal Strength Indicator)
- Output indication: LED

🔌 System Architecture

The system consists of two main units:

1. Transmitter Unit

The transmitter uses a NodeMCU ESP8266 to send data wirelessly to the receiver over the configured Wi-Fi network.

2. Receiver Unit

The receiver uses another NodeMCU ESP8266 configured as a Wi-Fi access point. It receives UDP packets and uses the RSSI-based threshold logic to control the indicator LED.

🔄 Working Principle

1. The receiver NodeMCU creates a Wi-Fi access point named "BusStop_AP".
2. The transmitter connects to the configured Wi-Fi network.
3. The transmitter and receiver exchange data using UDP communication.
4. The received signal strength is monitored as an indication of relative proximity.
5. The receiver compares the RSSI value against a configured threshold.
6. When the signal meets the configured condition, the LED indicates the detected proximity state.

Note: RSSI is an indirect indicator of proximity, not a precise distance measurement. Signal strength may vary due to obstacles, antenna orientation, interference, and environmental conditions.

🌐 Communication Configuration

Parameter| Value
Wi-Fi SSID| "BusStop_AP"
Receiver IP address| "192.168.4.1"
UDP port| "4210"
Serial Monitor baud rate| "115200"
Example observed RSSI readings| "-60 dBm", "-59 dBm"

These values describe the prototype configuration. The LED threshold and the exact data format should match the uploaded Arduino sketches.

💡 LED Indication

The LED is used to indicate whether the configured RSSI condition has been met.

For example, if the configured threshold is "-60 dBm", a reading of "-59 dBm" meets a condition of "RSSI >= -60".

The actual indication depends on the comparison implemented in the receiver code.

🧪 Testing and Results

The prototype was tested using two NodeMCU ESP8266 boards. UDP communication was observed through the Serial Monitor, with received signal-strength readings around "-60 dBm" and "-59 dBm".

The testing demonstrated wireless data exchange and the use of RSSI-based logic for an LED indication.

Add your actual hardware photograph, circuit diagram, and Serial Monitor screenshots here.

🚀 Applications

- Educational bus-arrival indication prototypes
- Wireless communication demonstrations
- Embedded networking experiments
- IoT-based proximity-monitoring concepts
- Student projects involving Wi-Fi and RSSI

⚠️ Limitations

- RSSI does not provide a reliable, exact distance measurement.
- Signal strength can fluctuate due to environmental conditions.
- The prototype does not independently determine a bus's GPS location.
- It does not use LoRa communication.
- Real-world deployment would require extensive testing and improved proximity detection.

🔮 Future Enhancements

- Calibrate RSSI thresholds under different environmental conditions.
- Add a buzzer or multiple LEDs for different indication states.
- Develop a mobile or web dashboard for monitoring.
- Investigate more reliable distance-estimation methods.
- Integrate GPS-based location reporting in a future version.
- Test the system under real bus-stop operating conditions.

📚 Learning Outcomes

Through this project, I explored:

- ESP8266 programming using Arduino IDE
- Wi-Fi access-point configuration
- UDP-based wireless communication
- RSSI monitoring and threshold-based decision-making
- LED interfacing with a microcontroller
- Debugging wireless communication using the Serial Monitor

👩‍💻 Author

Srimathi S

Electronics and Communication Engineering

Interested in Embedded Systems, IoT, Wireless Communication, and Space Technology.

📄 License

This project is intended for educational and learning purposes. A license can be added to specify how others may use, modify, and distribute the source code.