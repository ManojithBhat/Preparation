# Congestion Control 
congestion occurs when there are too many packets in the subnets degrading the performance of the network.

### Reason for congestion
- data from multiple input lines needs a single output line building up the queue.
- Low bandwidth links 
- Routers that process packets slowly.
> todo: add graph

#### Advantages of congestion control
- Increased network stability
- Reduced latency and packet loss
- Enhanced throughput. 
- Fairness in resource allocation
- Better user experience 


### General Principal of congestion control
- Open loop congestion control
- Closed loop congestion control


#### Open loop congestion control
The solves the problem by good design and make sure that the congestion doesn't occur at the first place. 

- deciding when to accept the traffic, discard the packets, and scheduling decisions and does not depend on the current state of the network.
- can be divided into source versus and at the destination.
#### Closed loop congestion control
- based on feedback loop and there are 3 parts
    1. Monitor the network to detect when and where the congestion occurs - takes into account packet discarded, queue length, # of packets timed out and retransmitted. 
    2. Pass this information to the place where action is taken - send `choke packet` 
    3. Adjust the network to correct the problem - congestion control technique.
> Probe packets - sent out by router to explicitly ask about congestion.

- Explicit - packets are sent back to warn about congestion
- Implicit - source deduces the info by observation.


> Two methodologies - increase the resources or decrease the load.



### Congestion control in virtual circuit network
- Admission Control
    - If the congestion is signaled in the network no more virtual circuits are set up until congestion is cleared.
    - Negotiate an agreement between the host and subnet when the virtual circuit is set up. - volume , traffic, qos and other parameter - resource reservation. 


### Congestion control in datagram subnet
#### Warning bit
- Whenever there is a congestion, the router sets the special bit in the packet's header. when this packet arrives at the destination, this bit is copied into the next acknowledgement and sent it to the source to cut down on the traffic.
- The source can adjusted the transmission as long as it receives the acknowledgement.
#### Choke Packet
- The purpose of choke packets is to provide feedback to the sender, notifying them of the network congestion and signaling them to reduce their data transmission rate.
- the host should ignore choke packets referring to that destination for a fixed time interval.
#### Hop by Hop Choke Packet
- For the long distance transmission choke packet becomes unreliable. 
- choke packet take effect at every hop it passes through.
- The net effect of this hop-by-hop scheme is to provide quick relief at the point of congestion at the price of using up more buffers upstream
#### Load Shedding
- load shedding refers to the routers to throw away or drop the packet when they are overflooded.
- In an intelligent discard policy, applications must mark their packets in **priority classes** to indicate how important they are. If they do this, then when packets have to be discarded, routers can first drop packets from the lowest class


#### Random Early detection ( RED )
- proactive approach
- **prevent network congestion** from becoming severe before it causes significant problems
- Instead of waiting until the router’s buffer is completely full and then dropping packets, RED gradually drops packets earlier, based on certain probability, to signal to the sender that congestion is building up.
- When the average queue length on some line exceeds a threshold, the line is said to be congested and action is taken. It picks the packet randomly from the queue and discards it. 
> It was designed for TCP connections 

#### Jitter control
> The variation in the packet arrival time is called as jitter.



- The jitter can be bounded by computing the expected transit time for each hop along the path. When a packet arrives at a router, the router checks to see how much the packet is behind or ahead of its schedule. This information is stored in the packet and updated at each hop. If the packet is ahead of schedule, it is held just long enough to get it back on schedule. If it is behind schedule, the router tries to get it out the door quickly. 


> todo: graph denoting the jitter ( variation )

- tter can be eliminated by buffering at the receiver and then fetching data for display from the buffer instead of from the network in real time.


