# Data link layer 


### Services provided by data link layer 
- provides service to the data link layer
- Node to node - duty and scope.
- Encapsulates the datagram coming from the network layer into frame and before providing it to the physical layer.
- It also decapsulates the frame. 
### Functions of Data link layer
- Framing
- Flow control 
- Error control 
- Congestion control


### Data Link Control Service 
Procedure for communication between 2 adjacent nodes 

### Framing
- Framing in the data-link layer separates a message from one source to a destination by adding a sender address and a destination address. 
#### Frame size 
- Fixed size framing - no need for delimiter as size defines the boundary and is used in ATM WAN
- Variable size framing -  In variable-size framing, we need a way to define the end of one frame and the beginning of the next. 
    - Character oriented framing ( byte oriented framing ) 
        - To separate one frame from the other a 8 byte flag is used at the beginning and ending of the frame 
        - **Byte stuffing** (or character stuffing), a special byte is added to the data section of the frame when there is a character with the same pattern as the flag.  
            - This byte is usually called as escape character ( ESC )
    - Bit Oriented Framing 
        -  In _bit-oriented framing, _the data section of a frame is a sequence of bits to be interpreted by the upper layer
        -  special 8-bit pattern flag, 01111110
        - **Bit Stuffing,** if a 0 and five consecutive 1 bits are encountered, an extra 0 is added. This extra stuffed bit is eventually removed from the data by the receiver.


### Flow Control 
- Understanding relation between the producer and the consumer rates.
- Our motive is to prevent the losing of the data at the consumer side.
- Concept of buffers to hold the packets at both the reciever and consumer side.
- Flow control in this case can be feedback from the receiving node to the sending node to stop or slow down pushing frames.
### Error Control
- CRC (cyclic redundant check) is added to the frame header by sender and checked by receiver.
- If frame is corrupted it is silently discarded and it could either acknowledge the correct frames or not ( in LANs such as ethernet ).
> DLC protocols can be either connectionless or connection oriented. 



## Data Link Layer protocol
The behavior of a data-link-layer protocol can be better shown as a finite state machine (FSM). An FSM is thought of as a machine with a finite number of states. The machine is always in one of the states until an event occurs.


### Simple Protocol
- Protocol with no error and flow control 
- It assumes that  receiver can immediately handle any frame it receives.

![](https://slideplayer.com/slide/14635911/90/images/19/Figure+111.8%3A+FSM+for+the+simple+protocol.jpg)


### Stop and wait protocol 
- both error and flow control 
  

![](https://slideplayer.com/slide/14635911/90/images/24/Figure+%3A+FSM+for+the+stop-and-wait+protocol.jpg)

> we use Sequence number as well as acknowledgement numbers to keep track of the duplicate packets and are valued 0 and 1



### Piggybacking
used for unidirectional communication where data in one direction is piggybacked with the acknowledgment in the other direction. 



## High Level Data Link Control ( HDLC )
 bit-oriented protocol for communication over point-to-point and multipoint links which uses stop n wait protocol.

### Configurations and Transfer Modes
- **Normal Response Mode ( NRM )**  station is unbalanced in which primary stations can send commands and secondary stations can only send response.
- **Asynchronous Balance Mode ( ABM )** - balance mode in which both primary and secondary stations can send commands/response.


### Framing  
There are 3 types of frame:

- Information frame ( I - frames ) - user data and control information 
- Supervisory frame ( S -frame ) - control information
- Unnumbered frames ( U - frame ) - system management


#### Frame description
- flag field 
- address field - to address if sent by primary station and from address if sent by secondary station 
- control field 
- information field - data
- FCS field - frame check sequence


##### Control fields for I frame
- first bit defines the type. 0 is for information frame
- N(S) - next 3 bits defines the sequence number.
- P/F bit - set to 1 mean poll ( primary --> secondary ) or final ( secondary --> primary )
- N(R) - next 3 bits - for acknowledgement when piggybacking is used.


#### Control fields for S frame 
- the first 2 bits - 10 mean supervisory frame.
- N(R) - last 3 bit  used for either ACK or negative ACK.
- P/F bit - same function as i frame.
- 4th ad 5th bit - code 
    - Receive ready ( 00 ) 
    - Receive not ready ( 10 ) 
    - Reject ( 01 ) 
    - Selective Reject ( 11 ) used in selective repeat 


#### Control frame for U frame
- first 2 bit is 11 
- used for connection establishment and release.
    - Set Asynchronous mode , Unnumbered frame , Disconnect


## Point to point protocol 
- Format of the frame to be exchanged.
- negotiation of the establishment of link and exchange of data.
- accept payload from several protocol. 
- Does not provide flow control.
- simple mechanism for error control.
- no addressing mechanism. 
- Provides authentication.
- Uses byte stuffing.


#### Framing
- Flag - 01111110
- Address - 11111111
- control 00000011 ( unnumbered frames in HDLC )
- Protocol - used data/other information
- Payload field - max of 1500 bytes. 
- FCS


#### Transition Phase diagram.

![](https://media.geeksforgeeks.org/wp-content/uploads/20200810233625/TTTTERR.png)

- starts with dead state -> establish state -> authentication -> network state -> data transfer in open state -> terminate -> dead. 
#### Multiplexing 
- Link control protocol - is responsible for establishing, maintaining, config uring, and terminating links
- 2 authentication protocol - Password Authentication Protocol, Challenge Handshake Authentication Protocol
- several network control protocol 


### Difference between HDLC and PPP
| **Basis of Difference** | <p>**HDLC**</p><p> (High-Level Data Link Control)</p> | <p>**PPP**</p><p> (Point-to-Point Protocol)</p> |
| ----- | ----- | ----- |
| **Definition** | Bit-oriented synchronous data link protocol. | Byte-oriented asynchronous data link protocol. |
| **Standardization** | Standardized by international standards organizations (e.g., ISO). | Standardized by IETF (Internet Engineering Task Force) and is an open standard. |
| **Encapsulation** | Can encapsulate data from different network layer protocols within its frames. | Can encapsulate multiple network layer protocols (e.g., IP, IPX) within its frames. |
| **Authentication** | Does not provide authentication mechanisms. | Provides authentication mechanisms (e.g., PAP, CHAP) to verify identity before establishing a connection. |
| **Application** | Used primarily in local area networks (LANs) for device-to-device communication. | Commonly used for dial-up, PPPoE (Point-to-Point Protocol over Ethernet), and WAN links (e.g., Internet connections). |


## Media Access Control 
Taxonomy

1. Random access protocol 
    1. ALOHA
    2. CSMA 
    3. CSMA/CD
    4. CSMA/CA
2. Controlled access protocol
    1. Reservation
    2. Polling 
    3. token passing
3. Channelization protocols 
    1. FDMA
    2. TDMA
    3. CDMA


### Random access / contention 
- assumes that no station is superior to another station.
- none is assigned control over the other. 
- no schedule time for a station to transmit - random access.
- no rules specify which station should send next - compete - contention methods.


### CSMA Carrier sense multiple access protocol
- CSMA requires each station to first listen to the medium before sending it. 
- It can reduce the possibility of collision but cannot eliminate it.
- The possibility of collision still exist because of propagation delay.


##### Vulnerable time 
- The length of time in which there is a possibility of collision.
- The vulnerable time for CSMA is the **propagation time Tp**. This is the time needed for a signal to propagate from one end of the medium to the other. 


### Persistence methods
#### 1-persistant
- In this method, after the station finds the line idle, it sends its frame immediately (with probability 1).
- This method has the highest chance of collision because two or more stations may find the line idle and send their frames immediately. 
#### Non - persistent
-  If the line is idle, it sends immediately.
- If the line is not idle, it waits a random amount of time and then senses the line again.
#### p - persistent 
1. check if the line is busy keep sensing the line ( like 1-persistent ) 
2. If the line is idle 
    1. Generate a random number R between 0 and 1. 
    2. Check if R <= p, if yes then transmit.
    3. if R> p then wait for a slot and sense the channel again. ( like non-persistent) 
    4. if the channel is idle start the step a. 
    5. else backoff process assuming that collision has occurred. 
> The backoff time TB is a random value that normally depends on K (the number of attempted unsuccessful transmissions).



### CSMA/CD - Carrier sense multiple access with collision detection (CSMA/CD)
In this method, a station monitors the medium after it sends a frame to see if the transmission was successful. If so, the station is finished. If, however, there is a collision, the frame is sent again.

##### Minimum Frame Size
the frame trans mission time Tfr must be at least two times the maximum propagation time Tp. 

> A network using CSMA/CD has a bandwidth of 10 Mbps. If the maximum propagation time (including the delays in the devices and ignoring the time needed to send a jamming signal) is 25.6 μs, what is the minimum size of the frame? 

> **Solution :** The minimum frame transmission time is Tfr = 2 × Tp = 51.2 μs. This means, in the worst case, a station needs to transmit for a period of 51.2 μs to detect the collision. The minimum size of the frame is 10 Mbps × 51.2 μs = 512 bits or 64 bytes.



> todo: add diagram



### CSMA/CA
Carrier sense multiple access with collision avoidance (CSMA/CA) was invented for wireless networks.

> todo

