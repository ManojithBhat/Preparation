# Network Layer 
The network layer is concerned with getting packets from the source all the way to the destination.

- Store and Forward packet Switching
    - A host with a packet to send transmits it to the nearest router, the packet is **stored** there until it has fully arrived and the link has finished its processing by verifying the checksum.
    - Then it is **forwarded** to the next router along the path until it reaches the destination host, where it is delivered.

-  Connectionless Service 
# Routing algorithms 
Purpose of the network layer is routing the packets from the source to the destination machine

- The routing algorithm is that part of the network layer software responsible for deciding which output line an incoming packet should be transmitted on.
- The properties of routing algorithm include fairness, optimality, correctness, robustness, stability and simplicity and stability. 
- **Non adaptive algorithm** - do not change their routing decision based on any measurement or estimate of the current topology and traffic. used in **static routing**
- **Adaptive algorithms** change their routing decisions to reflect changes in the topology and changes in the traffic as well. Used in **dynamic routing.**
### Optimality principle 
- If router J is on the optimal path from router I to router K, then the optimal path from the J to K also falls along the same route.
> Sink tree - optimal routes from all source to destination from a tree routed at the destination which contains no loop and each packet is delivered within finite and bounded number of hops.

## Shortest Path routing
- The metric used for determining the shortest path may include number of hops, distance in kms, bandwidth, delay, cost, average traffic and other parameters. 
- Widely used algorithm for this is Dijkstra which is the single source shortest path algorithm.
## Flooding
- It is a static algorithm in every incoming packet is sent out on ever outgoing line except the one it arrived on.
- In order to limit the generation of the infinite number of packets, hop counter is added in the header of the each packet where packets are dropped if the hop count hits zero. 
- The other way to limit is router keep track of which packets have been flooded to avoided sending them for second time, by putting the sequence number in each of the packet.
Practical application

- In military application to send the message instantly
- Distributed database to update all the database concurrently
- Wireless networks.
> Flooding always chooses the shortest path.



## Distance Vector Routing
- It is a dynamic algorithm which updates based on the current network load and topology.
- It is also known by Bellman ford Algorithm and Ford-Fulkerson algorithm. 
- A distance vector routing algorithm operates by having each router maintain a table (i.e., a vector) giving the best known distance to each destination and which link to use to get there. These tables are updated by exchanging information with the neighbors.
- The metric could be distance which is assumed to be known, hop count which is unity or the delay which is obtained by sending the `ECHO` packet.  
> the old routing table is not used in the calculation.



### The count to infinity problem.
> The settling of routes to best paths across the network is called **convergence.** 

- It arises when there is a network topology change, but the routing information does not propagate quickly or efficiently throughout the network. This can result in routers incorrectly believing that they have found the shortest path to a destination and creating routing loops
## Link State Routing
- The shortcoming of the distance vector routing ( i.e. Count to infinity problem ) is replaced by the another dynamic algorithm which is called as link state routing. ( IS-IS and OSPF ).
- Five simple steps in the link state routing is :
    1.  Discover its neighbors and learn their network addresses.
        1. Send the special `HELLO packet` on each p to p line.
        2. In LAN, there exist a designated router.
    2.  Set the distance or cost metric to each of its neighbors. 
        1. Get the cost / distance.
        2. Send the `ECHO packet` to get the delay.
    3. Building Link State Packets.
        1. Once the information needed for the exchange has been collected, the next step is for each router to build a packet containing all the data.
        2. The packet has following content.
            1. Address
            2. Sequence number 
            3. Age
            4. list of neighbors
    4. Distributing the Link State Packets.
        1. Flooding is used to distribute the link state packets.
        2. A sequence number is used to keep track of all pairs that router have come into and distributed.
        3. The packet also contains age field which is decremented every hop.
    5.  Computing the New Routes
        1. It constructs the entire network graph based on the link state packets it has received.
        2. This information is then used to compute the shortest path using the Dijkstra algorithm.


## Hierarchical Routing
- In this routing the routers are divide into regions with each router knowing all the details about how to route packets to destination within its own region and nothing about the internal structure of the other region.
- Regions --> Clusters --> Zones --> Groups.
> Optimal number of levels for N router subnet is ln(N) 


## Broadcast routing
> Sending a packet to all destinations simultaneously is called broadcasting

- method 1 - source send a distinct packet to each destination consuming bandwidth and source requiring to keep list of all the destination.
- method 2 - use flooding to distribute the packet - drawbacks of flooding still exist.
- **Muti-destination routing**
    - whenever a packet comes to the router, router checks all the destination to determine which set of output lines will be needed, a copy is made for each output line and includes packet only those destination to be used. 
    - drawback include source knowing all the destination and more work to each of the router.
- **Reverse path forwarding**
    - whenever a packet comes to the router, router checks to see if the packet arrived on the link that is normally used for sending packet  towards the source. yes, then this would be the best route and is the first copy to arrive and forwards copies into all lines else the packet is dropped.
> **Preferred Link**: If the router wants to send a packet _back_ to the source of the broadcast, it would have a preferred outgoing link, based on this routing table

- It requires building the sink tree for the route


## Multicast routing
> Send messages to well-defined groups that are numerically large in size but small compared to the network as a whole.



- **DVMRP (Distance Vector Multicast Routing Protocol)** - Use distance vector routing after pruning the spanning tree/ sink tree for the each group. The spanning tree is recursively pruned by sending`PRUNE` message by the router to all the neighbors which has received the packet which is not intended to get
- **Core-Based Tree** - single spanning tree per group is computed with the route near the middle of the group. To send multicast message a host send it to the core which does the multicast along the spanning tree.


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
  -  include deciding when to accept the new 
  

