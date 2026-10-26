# 🚗 CAN-Based Node Communication for Automotive

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Embedded%20Systems-green)
![Communication](https://img.shields.io/badge/Protocol-CAN-orange)
![IDE](https://img.shields.io/badge/IDE-MPLAB%20X-blueviolet)
![Status](https://img.shields.io/badge/Status-Source%20Code%20Available-success)

---

## 📖 Overview

The **CAN-Based Node Communication for Automotive** project is an embedded systems project focused on Controller Area Network (CAN) communication between multiple Electronic Control Units (ECUs).

The project contains three separate MPLAB X project directories representing automotive ECU nodes. It uses C programming and supporting peripheral drivers to implement embedded application functionality and CAN communication.

The project demonstrates the organization of multiple ECU software projects, CAN-related source modules, message identifiers, and peripheral interfaces in an automotive embedded systems environment.

## ✨ Features

- 🚘 Three separate ECU software projects
- 🔗 CAN communication-related source modules
- 💻 Embedded C programming
- 🧩 Modular source code using C and header files
- 🛠️ MPLAB X project configuration and Makefiles
- 🔧 Peripheral driver modules in the ECU projects
- 📡 Message identifier header files for CAN-related communication

## 🛠️ Technologies Used

- **Programming Language:** C
- **Communication Protocol:** Controller Area Network (CAN)
- **Development Environment:** MPLAB X IDE
- **Build System:** Makefiles generated for MPLAB X
- **Project Organization:** Modular embedded C source and header files

## 📁 Project Structure

```text
CAN-Based-Node-Communication-for-Automotive/
│
├── dashboard_EC1.X/
│   ├── adc.c
│   ├── adc.h
│   ├── can.c
│   ├── can.h
│   ├── clcd.c
│   ├── clcd.h
│   ├── main.c
│   ├── matrix_keypad.c
│   ├── matrix_keypad.h
│   ├── msg_id.h
│   ├── Makefile
│   └── nbproject/
│
├── dashboard_ECU2.X/
│   ├── adc.c
│   ├── can.c
│   ├── can.h
│   ├── clcd.c
│   ├── matrix_keypad.c
│   ├── ssd_display.c
│   ├── main.c
│   ├── msg_id.h
│   ├── Makefile
│   └── nbproject/
│
├── dashboard_ECU3.X/
│   ├── can_1.c
│   ├── can_1.h
│   ├── clcd.c
│   ├── clcd.h
│   ├── main_1.c
│   ├── msg_id_1.h
│   ├── Makefile
│   └── nbproject/
│
├── .gitignore
└── README.md
```

*Note: The structure above highlights representative files. Refer to each directory for the complete source code and project configuration.*

## 🔍 Project Components

### 1. `dashboard_EC1.X`

Contains the first ECU project, including CAN-related modules, ADC interfaces, character LCD drivers, matrix keypad drivers, and application source code.

### 2. `dashboard_ECU2.X`

Contains the second ECU project, including CAN-related modules, ADC interfaces, LCD and display drivers, keypad-related modules, and application source code.

### 3. `dashboard_ECU3.X`

Contains the third ECU project, including CAN-related modules, character LCD drivers, message identifier headers, and application source code.

## 🧠 Concepts Covered

- Embedded C programming
- Electronic Control Units (ECUs)
- Controller Area Network (CAN)
- Modular embedded software design
- C source files and header files
- Peripheral driver organization
- Message identifier definitions
- MPLAB X project structure and build configuration

## 🚀 Getting Started

### Prerequisites

- MPLAB X IDE
- A compatible Microchip compiler configured for the target device
- The appropriate hardware and CAN interface for physical communication testing

### Steps

1. Clone or download this repository.
2. Open MPLAB X IDE.
3. Open one of the project directories, such as `dashboard_EC1.X`.
4. Check the project's device and compiler configuration.
5. Build the project using the configured toolchain.
6. Repeat for the other ECU projects as required.

**Note:** Successful compilation and hardware execution depend on the target microcontroller, compiler version, project configuration, and required hardware. These have not been independently verified here.

## 🎯 Learning Outcomes

This project provides experience with:

- Organizing multiple embedded ECU projects
- Understanding CAN-related software modules
- Structuring embedded applications in C
- Working with peripheral driver source files
- Managing message identifier definitions
- Using MPLAB X project files and Makefiles

## 👨‍💻 Author

**Rajath H M**

- GitHub: [Rajath-Arya](https://github.com/Rajath-Arya)

---

⭐ If you find this project useful, consider giving the repository a star!
