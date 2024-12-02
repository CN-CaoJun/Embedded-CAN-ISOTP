# Embedded-CAN-ISOTP
## Introduction
Embedded-CAN-ISOTP is an embedded implementation of the Transport protocol and network layer services. It is primarily designed for use with RTOS (Real-Time Operating Systems) and provides a portable layer for easy integration. The ISO-TP (ISO Transport Protocol) implemented in this project adheres to the ISO15765-2 standard, ensuring compatibility and standardization. Additionally, the project supports both CAN TP (Controller Area Network Transport Protocol) and CAN FD TP (Controller Area Network with Flexible Data-Rate Transport Protocol), catering to different communication requirements within automotive and embedded systems.
## Framework

The framework for implementing CAN TP (Controller Area Network Transport Protocol) in the Embedded-CAN-ISOTP project is structured as follows:

<div style="text-align: center;">
  <img src="./docs/cantp_framework.drawio.png" alt="Image Description" width="500">
</div>
- Application Layer: This layer is where the application interacts with the transport protocol. It is responsible for initiating and managing the communication sessions.

- Transport Layer: The ISO-TP (ISO Transport Protocol) is implemented at this layer. It adheres to the ISO15765-2 standard and provides the necessary transport services for CAN and CAN FD networks.

- Portable Layer: This layer provides a set of APIs (Application Programming Interfaces) for the transport protocol. It includes functions for opening, reading, writing, and controlling the CAN hardware. This layer is designed to be portable across different RTOS (Real-Time Operating Systems) and MCU (Microcontroller Unit) platforms.

- CAN Hardware: This layer represents the physical CAN hardware, which is responsible for transmitting and receiving data over the CAN bus.

- Platform: This layer includes the RTOS (Real-Time Operating Systems) and MCU (Microcontroller Unit) platforms. The project supports various RTOS platforms such as FreeRTOS, ThreadX, and Zephyr.

## Usage
TBD
