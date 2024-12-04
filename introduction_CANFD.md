# CAN-FD Protocol

# CAN-FD Protocol: Enhancing Data Transfer Rates and Performance in Modern Vehicles

CAN FD Protocol, also known as Controller Area Network Flexible Data-Rate, is a data-communication protocol that has gained popularity in the automotive industry due to its ability to enhance data transfer rates and performance. [Bosch ](https://www.bosch.in/)CAN FD is a widely used implementation of this protocol, which has been designed to meet the specific needs of modern vehicles. Discover the essential components of the automotive can protocol in CAN FD protocol vehicles, a comprehensive system designed to enhance the performance and safety of vehicles.

## Introduction to CAN-FD Protocol

The main limitation of the traditional [CAN](https://piembsystech.com/can-protocol/) network is the restricted bandwidth, which is the maximum of 1 Mbit/s on a 40-meter CAN-bus. The CAN-Flexible Data Rate nothing but the CAN-FD protocol is a new standard developed by Bosch in the year of 2011 aiming to increase the bandwidth of the CAN bus while retaining the core characteristics of the traditional CAN bus. Then after one year of lab tests, they have released it in the year of 2012. The bandwidth restriction in CAN arises due to the arbitration feature available in the CAN protocol, which is used in the standard CAN.

On a CAN bus, multiple nodes are allowed to transmit at the same time before the higher priority message wins the arbitration. Suppose the sender A does at ID 7 In order for the arbitration scheme to work for all communication on the bus. Then the signals from a node must be able to propagate through the entire length of the CAN bus and back again. In order to ensure corresponding bits are compared in the arbitration scheme, even for the nodes, which are furthest away from each other. However, once the higher priority node gains access to the CAN bus only one node will be [transmitting ](https://en.wikipedia.org/wiki/Transmitter)data. By utilizing this characteristic of the CAN bus it is possible to transmit data at a higher rate once there is only one node transmitting on the bus. This is the main idea behind the new standard called CAN-FD protocol.

### What is CAN FD Protocol?

CAN-FD Protocol, a part of the Controller Area Network (CAN) family, is a data-communication protocol used in modern vehicles for broadcasting sensor data and control information on 2-wire interconnections between different parts of the automotive system. Developed by Bosch to enhance data transfer rates and performance, CAN-FD is an extension to the original CAN bus protocol specified in [ISO 11898-1](https://www.iso.org/standard/63648.html). The protocol operates at the lower layers of the [OSI ](https://en.wikipedia.org/wiki/OSI_model)reference model, specifically layers 1 to 4, while the higher layers are used for application-specific protocols and communication profiles.

### **What Is the Need of CAN-FD Protocol?**

The automotive technologies are changing in every year as the customer expectation is increasing. If you will look onto the vehicle there are so many features are adding in automotive ECU. To prevent this they want a protocol that can send a bigger data packet in a single frame and also the data rate is 5-10 Mbps. In the current times, only the CAN protocol mostly used for [ECU ](https://piembsystech.com/car-ecus/)communication. It is nothing like there is no other protocol like [FlexRay](https://piembsystech.com/flexray-protocol/), [MOST](https://piembsystech.com/most-protocol), etc. available but the CAN is better than them if you will compare them with cost and safety. Even if you also can get a better data rate but it will be high cost.

There is the main reason also that there are most of the vehicles are now having CAN protocol. The OEM does not want to change it which will cost them both from customer and development. Even if the OEM will change that since there is no way of option, then what Robot BOSCH will do if everyone will remove the CAN? How they will earn the money?

Then the Robot BOSCH started to research and development of advanced CAN protocol called CAN-FD protocol. The CAN-FD protocol has a lot of advanced features over the standard classical CAN protocol. Let us discuss below the difference between the CAN protocol and CAN-FD protocol.

## Properties of CAN-FD Protocol

- Prioritization of messages:
- Guarantee of latency times;
- Configuration flexibility:
- Multicast reception with time synchronization:
- System wide data consistency.
- Multimaster
- Error detection and signalling.
- Automatic retransmission of corrupted messages as soon as the bus is idle again.
- Distinction between temporary errors and permanent failures of nodes and autonomous switching off of defect nodes.
- Compatibility with CAN protocol, every CAN FD node is able to receive and to transmit CAN messages according to ISO 11898-1

### Safety in CAN-FD Protocol

In order to achieve the utmost safety of data transfer, powerful measures for error
detection, signalling and self-checking are implemented in every CAN FD node.

- Error Detection: For detecting errors the following measures have been taken:
- Monitoring (transmitters compare the bit levels to be transmitted with the
    bit levels detected on the bus)
- Cyclic Redundancy Check
- Bit Stuffing
- Message Frame Check
- Performance of Error Detection
    The error detection mechanisms have the following properties:
- all global errors are detected.
- all local errors at transmitters are detected.
- up to 5 randomly distributed errors in a message are detected.
- burst errors of length less than CRC Sequence in a message are detected.
- errors of any odd number in a message are detected. Total residual error probability for undetected corrupted messages: less than message error rate * 4.7 * 10-11.

## CAN-FD in OSI Layer

In the OSI model, the CAN-FD protocol covers the data link layer (DLL) and the physical coding sub-layer (PCS), as well as the physical medium attachment (PMA) sub-layer. The medium-dependent interface sub-layer is generally application-specific, and the other layers are usually referenced as higher-layer protocols (HLP). Some of the companies behind the CAN-FD standard include STMicroelectronics, Infineon, NXP, Texas Instruments, Kvaser, Daimler, and GM.

### **CAN-FD Physical Layer Design**

The CAN-FD protocol physical layer design is different from standard classical CAN protocol. The CAN-FD controller is not that much change but in transceiver design, it is totally different to make the compatibility of new high bandwidth and payload support.

The Physical Layer is responsible for managing bits and determining the method of transmitting signals. This involves describing Bit Timing, Bit Encoding, and Synchronization. However, the characteristics of the electrical driver/receiver for the Physical Layer are not specified in order to permit customization of transmission medium and signal level implementations for their specific applications.

### CAN-FD Data link layer

The Data Link Layer handles frames and consists of the two sublayers:

![Layered Architecture of CAN FD Protocol in OSI Layer](https://piembsystech.com/ezoimgfmt/i0.wp.com/piembsystech.com/wp-content/uploads/2023/04/Layered-Architecture-of-CAN-FD-Protocol-in-OSI-Layer.jpg?resize=774%2C819&ssl=1&ezimgfmt=rs:774x819/rscb2/ng:webp/ngcb2)

- Logical Link Control (LLC)
- Medium Access Control (MAC)

#### LLC sublayer of the Data Link Layer

The LLC corresponds to the node’s controller-host interface and is concerned with Message
Filtering, Overload Notification and Recovery Management. Its scope is

- to decide which messages received by the MAC sublayer are actually to be
    accepted,
- to provide services for data transfer and for remote data request,
- to provide messages to the MAC sublayer for transmission,
- to provide means for recovery management and overload notifications.
    There is much freedom in defining object handling.

#### MAC sublayer of the Data Link Layer

The MAC sublayer assumes responsibility for several key functions, including Message Framing, Arbitration, Acknowledgment, Error Detection, and Signalling. To ensure system integrity, a self-monitoring mechanism called Fault Confinement supervises the MAC sublayer and distinguishes between brief disruptions and sustained failures. Within the MAC sublayer, determinations are made about whether the bus is available for a new transmission or if a reception is in progress. As the heart of the CAN FD protocol, the MAC sublayer cannot be modified.

## **CAN-FD Protocol Message Frame Format**

The CAN-FD protocol is having its own frame format. Though there is not a lot of changes, some changes are there to support the new features as well as how it can also work with standard classical CAN network. Except for the Data frame, other frames are the same so let us discuss the CAN-FD data frame. If you will look at the below figure there are some fields have different. I would like to request you that if you have any doubts about the data frame please go to my CAN protocol tutorial. Here we will only discuss the advanced fields added in CAN-FD protocol.

![CAN FD Protocol Frame Format Diagram](https://piembsystech.com/ezoimgfmt/i0.wp.com/piembsystech.com/wp-content/uploads/2024/01/CAN-FD-Protocol-Frame-Format.jpg?resize=1099%2C225&ssl=1&ezimgfmt=rs:796x163/rscb2/ng:webp/ngcb2)

### **Substitute Remote Request (SRR)** in CAN FD Protocol

The IDE bit is exclusively defined for Extended frames (IDE=1) and serves a different purpose in the Base frame when IDE=0. In the 29-bits frame formats CEFF and FEFF where IDE=1, this bit replaces the RTR-bit in CBFF and the RRS-bit in the FBFF. It is always sent as recessive (SRR=1) for both frame formats, and CAN FD receivers will accept SRR=0 without triggering a form error.

### **IDentifier Extension (IDE)** in CAN-FD Protocol

Unlike the bits previously described, the Identifier Extension (IDE) bit always maintains the same name and is transmitted in the same time slot. For both the CAN Basic Frame Formats (CBFF) and CAN Extended Frame Formats (FBFF), the IDE bit is dominant, meaning it is transmitted as a dominant bit in any Base Frame Format (frames with an eleven-bit ID) and any Extended Frame Format (frames with a twenty-nine-bit ID). In summary:

- IDE bit is always dominant in CBFF and FBFF frames.
- IDE bit is always transmitted in the same time slot.
- IDE bit is dominant in Base Frame Formats (CBFF and FBFF) and Extended Frame Formats (CEFF and FEFF).

### **Remote Request Substitution (RRS)**

In the CAN FD (Controller Area Network with Flexible Data-rate) protocol, the “RRS” bit, or “Remote Request Substitution” bit, is a feature within the extended frame format. When a device sends a Remote Transmission Request (RTR) frame, the RRS bit comes into play, enabling the requester to receive the requested data within the RTR frame itself, eliminating the need for a separate Data frame.

This feature aims to enhance communication efficiency by reducing latency, as the inclusion of data in the RTR frame streamlines the process. When the RRS bit is set (high), it signals that the data requested should be incorporated in the RTR frame, while a clear state (low) maintains the standard behavior, necessitating a separate Data frame for transmitting the requested data.

### **FD Format indicator (FDF)** in CAN-FD Protocol

This bit, referred to as the FDF (FD frame) bit, distinguishes between classical CAN and CAN FD frames. It is dominant in the classical CAN frame formats (CBFF and CEFF) and recessive in the CAN FD frame formats (FBFF and FEFF). The FDF bit is not consistently transmitted in the same time slot. In the Base frame formats (CBFF and FBFF), the FDF bit is transmitted in the control field just after the IDE bit.

Due to the extended arbitration field in frames with 29-bit identifiers (CEFF and FEFF), the FDF bit is transmitted after the RTR or RRS bits, respectively, in extended frame formats. This ensures that the FDF bit remains in the control field and is never included in arbitration.

### **Reserved bit in FD Frames (res)** in CAN-FD

The FDF (FD frame) bit is unique to CAN FD frames and is always transmitted as dominant. It is reserved for future use and is expected to be utilized in CAN XL, a later protocol tutorial. Since it is transmitted as part of the control field, it is not used in arbitration. Interestingly, it is called the r0 bit only in classical extended frames (CEFF), but still transmitted in the same state as dominant. The reason for the naming differences and the existence of this bit is for backward compatibility with previous versions of ISO 11898.

### **Bit Rate Switch (BRS)** in CAN-FD

The BRS (Bit Rate Switch) bit is a novel feature introduced in the CAN FD protocol, distinguishing it from classical CAN. It enables the bit rate to be increased up to 8 Mbps after the arbitration field is transmitted. The BRS bit is part of the control field and is always transmitted just after the res bit. It indicates whether the bit rate will remain the same or switch to a faster rate.

During the arbitration field, which is always transmitted at the nominal bit rate, if the BRS bit is recessive, the bit rate will switch to a higher data bit rate at the sample point of the BRS bit. The BRS bit is unique in that its state determines a timing shift at its own sample point. If the BRS bit is sampled as recessive, the bit rate will switch to the data bit rate, and sample points will adjust accordingly. If the BRS bit is sampled as dominant, the bit rate will remain the same for the remainder of the CAN FD frame.

### **Error State Indicator (ESI)** in CAN-FD

The Error State Indicator (ESI) bit is a newly introduced feature exclusive to CAN FD. It is utilized by a CAN FD node to communicate its error state. When transmitted as dominant, the ESI bit indicates that the node is in an error active state, while a recessive transmission signifies an error passive state. Always located in the control field, the ESI bit follows the Bit Rate Switch (BRS) bit, making it the first bit to be transmitted at the data bit rate in all CAN FD frames with BRS enabled. This bit is crucial for error state indication and is a significant addition to the CAN FD protocol.

### **Extended Data Length (EDL) in CAN-FD:**

In the CAN FD (Controller Area Network with Flexible Data-rate) protocol frame format, Extended Data Length (EDL) is a feature that allows for an increased data length compared to the classic CAN protocol. In standard CAN frames, the data length is limited to 8 bytes, but with CAN FD, the EDL feature enables data lengths of up to 64 bytes.

![CAN fd protocol](https://piembsystech.com/ezoimgfmt/i0.wp.com/piembsystech.com/wp-content/uploads/2020/04/CAN_Id.jpg?resize=650%2C207&ssl=1&ezimgfmt=rs:796x300/rscb2/ng:webp/ngcb2)***CAN – FD Arbitration\***

## Data Consistency in CAN-FD Protocol

The host prepares messages for transmission, which are then transferred through the node’s controller-host interface and LLC sublayer of the Data Link Layer to the MAC sublayer responsible for Message Framing. These messages may be stored in a shared memory, and ensuring data consistency of transmitted messages from this shared memory can be accomplished by at least one of two methods:

- Before transmission begins, the MAC sublayer must fill a temporary buffer with the entire message to be transmitted.
- While transferring the message to the MAC sublayer, the LLC sublayer is responsible for checking data errors. If any data error is found, the transmission cannot be initiated. If the transmission has already begun when a data error is detected, the node must switch to Bus Monitoring Mode. In such cases, receiving nodes will not receive a valid message.

## Different Operation Modes in CAN-FD Protocol

The operational states of a CAN FD unit are categorized into four, namely: Integrating, Idle, Receiver, and Transmitter, and each of them is defined as follows:

- **Integrating Mode:** During the start of the controller or during bus_off recovery, a unit is said to be in the Integrating state, during which it remains idle until it detects eleven consecutive recessive bits. Once it detects the required number of recessive bits, the unit switches to the Idle state.
- **Idle Mode:** When a unit is ready to receive or transmit data, it is in the Idle state. In this state, the unit is waiting for a START OF FRAME signal and can switch to either the Receiver or Transmitter state depending on the requirements of the communication.
- **Receiver Mode:** If a unit detects activity on the CAN bus and is not functioning as a Transmitter, it operates in the Receiver state.
- **Transmitter Mode:** When a unit initiates a message transmission, it is operating in the Transmitter state. The unit remains in this state until either the bus becomes idle or it loses ARBITRATION.

## Bus Monitoring Mode in CAN-FD Protocol

The CAN FD node can operate in an optional Bus Monitoring Mode, during which it can receive both valid DATA FRAMES and valid REMOTE FRAMES, but it cannot initiate a transmission and only sends recessive bits on the CAN bus. If the CAN FD protocol controller needs to send a dominant bit, such as an ACK SLOT, OVERLOAD FLAG, or ACTIVE ERROR FLAG, the bit is internally rerouted so that the controller can monitor it, even though the CAN bus may still be in a recessive state.

## Different types of Frame Formats in CAN-FD Protocol

There are four different formats which differ in the length of the ARBITRATION FIELD and
in the CONTROL FIELD:

- CAN BASE FORMAT: 11 bit long identifier and constant bit rate
- CAN EXTENDED FORMAT: 29 bit long identifier and constant bit rate
- CAN FD BASE FORMAT: 11 bit long identifier and dual bit rate
- CAN FD EXTENDED FORMAT: 29 bit long identifier and dual bit rate

## FRAME TYPES

Message transfer is manifested and controlled by four different frame types:
A DATA FRAME carries data from a Transmitter to the Receivers. There are four subtypes
of DATA FRAME in CAN FD:

- DATA FRAME in CAN BASE FORMAT
- DATA FRAME in CAN EXTENDED FORMAT
- DATA FRAME in CAN FD BASE FORMAT
- DATA FRAME in CAN FD EXTENDED FORMAT