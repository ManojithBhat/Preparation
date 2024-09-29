# Transport Layer 
It has 2 main protocols : UDP ( connectionless ) and TCP ( connection Oriented )

## User datagram protocol
- IP supports the connectionless protocol called as UDP and a way for application to send encapsulated datagram without establishing the connection.
- It does not support the flow control, error as well as transmission it only provides the interface to the IP
#### USE CASE OF UDP
- Client server architecture. 
- Domain name services.


#### UDP Header format
- UDP transmits the segment of 8 byte header and a payload.
-  Header contents
    - The source port is primarily needed when a reply must be sent back to the source. 
    - UDP length field includes the 8-byte header and the data.
    - An optional Checksum is also provided for extra reliability.
    - The destination port
## Transmission Control Protocol
- TCP was designed to provide reliable end to end byte stream over an unreliable internetwork.
- TCP entity accepts user data streams from local process breaks them into pieces and sends each of them as IP datagram, similarly they are given to TCP entity to reconstruct the original byte DataStream.
### Sockets 
- TCP service is obtained by both the sender and the receiver creating end points, called **sockets**.
- Each socket has a number ( IP address + Port ( 16 bit ) )  



| **Primitive**   | **Description**                                                                 |
|-----------------|---------------------------------------------------------------------------------|
| `socket()`      | Creates a new socket. The socket can be of various types, such as TCP (SOCK_STREAM) or UDP (SOCK_DGRAM). |
| `bind()`        | Binds the socket to a specific address and port number. This is usually done on the server side. |
| `listen()`      | Prepares the socket to accept incoming connections (used in TCP server sockets). |
| `accept()`      | Waits for an incoming connection and returns a new socket connected to the client. |
| `connect()`     | Connects the socket to a remote address (used by clients to connect to a server). |
| `send()`        | Sends data through the socket. For TCP, it sends data reliably; for UDP, data may be lost. |
| `recv()`        | Receives data from the socket. Used for connection-oriented (TCP) communication. |
| `close()`       | Closes the socket and frees up resources. |

![](https://www.labs.cs.uregina.ca/330/Sockets/server-client.png)

- port number below 1024 is called as well known ports and are reserved for standard services. 


1. **Port 20** - FTP (File Transfer Protocol) Data Transfer
2. **Port 21** - FTP (File Transfer Protocol) Command Control
3. **Port 22** - SSH (Secure Shell)
4. **Port 23** - Telnet (Unencrypted Text Communication)
5. **Port 25** - SMTP (Simple Mail Transfer Protocol)
6. **Port 53** - DNS (Domain Name System)
7. **Port 80** - HTTP (HyperText Transfer Protocol)
8. **Port 110** - POP3 (Post Office Protocol v3)
9. **Port 143** - IMAP (Internet Message Access Protocol)
10. **Port 443** - HTTPS (HyperText Transfer Protocol Secure)
> inetd ( internet daemon ) attach itself to the multiple ports and wait for the incoming connection, it forks of new process and executes appropriate daemon in it, thus not cluttering up memory at the boot time.



- All connections are `full duplex and point to point and doesn't support multicasting and broadcasting`.
- TCP connection is `byte streamed` and not message streamed ( boundaries are not well preserved ).
- Every byte on the TCP has its own `32 bit sequence number` 
- TCP uses `sliding window protocol` 
- TCP entity sends back the `acknowledgment` bearing number equal to the next expected receive.
### TCP header 
![](https://www.gatevidyalay.com/wp-content/uploads/2018/09/TCP-Header-Format.png)

- It has 20 byte fixed header followed by header option.
- Source and destination port field - each of 16 bit long
- Sequence and acknowledgment number - each of 32 bit long.
- TCP header length - 4 bit long - 5 size fixed
- 6 bit unused.
- 1-bit flags
    - URG flag 
    - ACK flag - indicate the ACK number is valid
    - PSH - push flag - not to delay until last byte arrival in buffer
    - RST - reset the connection
    - SYN bit ( for connection req and connection ack ) 
    - FIN release the connection.
- window size - 16 bit - how many byte to send starting from byte ack
- Check sum - reliability and use pseudo header.
- Urgent pointer 


### TCP Connection Establishment
- By the means of three way handshake.
- **Server side**- passively waits for the incoming connection by executing `LISTEN` and `ACCEPT` primitives.
- **Client Side**- executes the `CONNECT` primitive specifying the IP addr and port address it want to connect along with TCP header contents. It sends with SYN bit 1 and ACK bit 0.
- **Server side**- when the segment arrives at the destination, TCP entity is checked whether there is any process that has done listen on the port.
    - If not it sends the segment with RST bit on to reject. 
    - If some process is listening then process is given the segment, which can either accept or reject. if it accepts then SYN and ACK bit is set to 1.  
### TCP connection Release
> The side that **initiates** the termination of the connection is said to perform an **active close**.

> The side that **waits for the other** to initiate the termination of the connection is said to perform a **passive close**.

- It is performed by four way handshake. 
- Each simplex connection is released independently.
- To release the connection one of the end can send a TCP segment with the FIN bit set ( Active close ).
- When the FIN is acknowledged that direction is shutdown for new data, however the data may continue to flow from the other side ( which has not initiated the close ).
- When the other side of the connection is done with the transfer it also sends the TCP segment with the FIN bit set ( Passive close ).
- The active closer responds with an **ACK** to confirm the receipt of the second FIN, fully closing the connection.
> Two-army problem :   is a theoretical problem in communication, where two groups (armies) need to coordinate an attack but cannot guarantee message delivery. Even if they send acknowledgments of received messages, they cannot be sure the acknowledgment was received by the other side. This creates an endless loop of uncertainty, making coordination impossible.

- To avoid two army problem, If no acknowledgment is received within **two maximum packet lifetimes**, the sender of the FIN assumes the other side won’t respond and releases the connection. Eventually, the other side will also time out and release the connection, preventing indefinite waiting and ensuring that both sides eventually close the connection gracefully.
### TCP Transmission Policy
> Senders are not required to transmit data as soon as they come in from the application. Neither are receivers required to send acknowledgements as soon as possible. 

