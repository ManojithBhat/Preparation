### Network Layer Part 2

Topics covered
* Congestion Control
* Quality of Services

## Congestion Control

When too many packets are present in the subnet the performance decreases and this situation is called as ```congestion```

#### Reason for congestion
* lots of incoming packets and single outgoing line for those packets.
* slow processor of routers.
* Low bandwidth lines. 

#### Difference between congestion control and flow control

Congestion involves making sure that network is able to carry the load, it is the global phenomenonand involves all the host, routers and processers etc.
Flow refers to the point to point traffic between sender and reciever and depends on the capacity of those. 

## General Principals of Congestion control
Divide the solution into 2 groups : 
- open loop - solve the problem by good design ie. it does not occur at the first place
  -  midcourse correction are not made. 
  -  iclude deciding when to accept the new 