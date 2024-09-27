# Introduction to Computer Networks

### Multiplexing
- synchronous time division method  - use round robin
- Frequency division method - transmit at the different frequency
- Statistical multiplexing - upper bound is called as a packet. 


### Networks
Interconnection of set of devices ( host - computer, desktops, laptop , routers, switches, modems ) that are capable of communication.

Criteria for network:

- Performance - throughput and delay.  
- Reliability - frequency of failure. 
- security 
## Physical Structures

#### Type of connection
- **Point to point connection** - dedicated link between the two devices. 
- **Multipoint connection** - more than two devices share a single link. 
#### Network Topology 
The way in which a network is laid out physically. 

Geometric representation of the relationship of all the links. 

- **Mesh topology**- dedicated point to point link to every other devices. 
- **Star topology**- point to point to link to a central controller called hub. 
- **Bus topology**- multipoint - one long cable act as a backbone and the nodes are connected to it by droplines and taps. 
- **Ring topology** - point to point connection with only two devices on either side of it and repeaters are used at every devices. 
#### Network Types
- **Local Area Network ( LAN )**
    - Interconnects devices within a single organization.
    - Each host in a LAN has an identifier i.e. address and a packet sent by one host to another host contains both source and destination address. 
- **Wide Area Network ( WAN )**
    - spans the wider geographical area like town state country I
    - Interconnects switches, routers and modems.
    - Created and run by a communication companies
    - Types of WAN 
        - point to point WANs 
        - Switched WANs 


#### Switching
The purpose of the switching is to forward the data from one network to the another network when required.

- **Circuit switched network** - Dedicated connection ( circuit ) made available between the two end systems. It is inefficient while working at the full capacity.
- **Packet Switched Network** - Communication between the two ends is done in the blocks of data called as a packet - use store and forward mechanism. 
#### Internet 
- internetwork ( lowercase i ) refers to the interconnected networks that communicate with each other. 
- Internet ( uppercase i ) refers to the global public network that contains millions of interconnected network.
- Broad overview of the Internet 
    - **Backbones **- large network owned by companies such as AT&T, Verizon which are connected by switching systems called as peering points.
    - **Provider network** - connected to the backbones and get service for a fee. 
    - **Customer network** - edge of the internet who uses the service provided by the internet.


## TCP/IP Suite
- set of protocols organized into different layers used in the internet today.
- It is a hierarchical protocol made up of interactive modules, each of which provides a specific functionality and upper layer uses the services provided by the lower layers.


- It has 5 layers
    - Application Layer 
    - Transport Layer
    - Network Layer
    - Data Link Layer
    - Physical Layer 

<br>

![TCP/IP suite](https://afteracademy.com/images/what-is-the-tcp-ip-model-and-how-it-works-tcp-ip-model-five-layers-195bdaa7116cd850.jpg)


## Brief Description of each layer 
### Physical Layer 
- Responsible for carrying the _**bits**_ in a frame across the link through the transmission medium in the form of electrical or optical signals.
- Bits are received in a frame from the data link layer are transformed and sent through the transmission media.
- some of the protocols in physical layer are : 
    - Ethernet ( IEEE 802.3 )
    - Wi-Fi ( IEEE 802.11 )
    - USB
    - DSL ( Digital Subscriber line ) 
    - Bluetooth
### Data Link Layer 
- The datalink layer takes the datagram and encapsulate it in a packet called **_frame_**.
- The purpose of the datalink layer is ensure reliable data transfer between the connected devices over a physical network link.
- It uses **MAC address** to ensure the data is sent to the correct device on the local network. 
- It provides mechanism for 
    - Framing
    - Error detection
    - Flow control 
    - Media access control ( How devices share access to the physical medium )
- some of the protocols in physical layer are : 
    - Ethernet.
    - Point to point protocol ( PPP )


> The duty of the datalink layer and physical layer is hop to hop in which hop is a host or router. whereas  application, transport, and network layers is end-to-end.

### Network layer 
- Responsible for creating the connection between the source and destination computer by choosing best and shortest route to the destination. 
- The primary Protocol used in network layer is **Internet protocol (IP) **
- The network layer also has some auxiliary protocols that help IP in its delivery and routing tasks. 
- The **Internet Control Message Protocol** (ICMP) helps IP to report some problems when routing a packet. 
- The **Internet Group Management Protocol** (IGMP) is another protocol that helps IP in multitasking. 
- The **Dynamic Host Configuration Protocol** (DHCP) helps IP to get the network-layer address for a host. 
- The **Address Resolution Protocol** (ARP) is a protocol that helps IP to find the link-layer address of a host or a router when its network-layer address is given.
### Transport Layer
- The **main purpose** of the **Transport Layer** in the TCP/IP model is to provide reliable data transfer between devices (hosts) on a network. It ensures that data is delivered accurately, in order, and without errors. This layer manages the end-to-end communication between applications running on different devices.
- The two main protocol that operates in this layer are 
    - Transmission Control Protocol ( TCP ) - connection-oriented and provides flow, error and congestion control.
    - User Datagram protocol ( UDP ) - connectionless protocol 
    - Stream Control Transmission Protocol 
- It encapsulate the data from the application layer into segment or datagram.
### Application Layer 
- Communication is between the two process. 
- The data is called as message in this layer.
- Some of the important protocols at this layer is :
    - HTTP
    - HTTPs
    - FTP
    - SMTP
    - TELNET
    - SSH
    - DNS
    - WWW


## OSI model 
- It stands for Open system Interconnection model in ISO standard.
- The purpose of the OSI model is to show how to facilitate communication between different systems without requiring changes to the logic of the underlying hardware and software.
- It consist of 7 layers : 
    - Application Layer
    - Presentation Layer
    - Session Layer
    - Transport Layer
    - Network Layer
    - Data Link Layer
    - Physical Layer


### Session Layer 
- controls the dialogues (connections) between computers. 
- It establishes, manages, and terminates the connections between the local and remote application.
### Presentation Layer 
- prepares data for the application layer by encoding encoding and compressing the data.


![OSI Model](https://www.imperva.com/learn/wp-content/uploads/sites/13/2020/02/OSI-7-layers.jpg) 

## Data Name and Addressing Used in each Layer


| **Layer (TCP/IP)** | **Layer (OSI)** | **Data Name** | **Addressing Used** |
| ----- | ----- | ----- | ----- |
| **Application** | Application, Presentation, Session | <p>**Data**</p><p> or </p><p>**Message**</p> | **Names and Port Numbers** |
| **Transport** | Transport | <p>**Segment**</p><p> (TCP) or </p><p>**User Datagram**</p><p> (UDP)</p> | **Port Numbers** |
| **Internet** | Network | **Packet** | <p>**IP Address**</p><p> (Logical Address)</p> |
| **Link** | Data Link + Physical | **Frame** | <p>**MAC Address**</p><p> (Physical Address)</p> |
| **Physical** | Physical | **Bits** | No Addressing (Physical Layer concerns transmission only) |




### Transmission Modes  
-  parallel transmission
- Serial Transmission
    - Asynchronous Transmission - timing of the signal is not important and extra bit is added to the start and end bit called as start and stop bit to notify the receiver about the arrival of the new group.
- Synchronous Transmission - bit stream is combined and there is no gap between each byte.
- Isochronous Transmission - data arrive at the fixed rate. 


