# Operating system

### What is an operating system? 
A program that manages the computer resources and hardware, it acts an intermediary between the computer users and computer hardware.

#### Functions of an operating system.
- Process management
- Memory management
- Storage management
- Protection and security
- Device management
- File management
- Error detection and communication


### Types of operating system
- **Batch OS** -  are computing environments where tasks are processed in batches, without the need for immediate user interaction. The jobs are submitted to the system one at a time, and each job is executed sequentially. This means that once a job begins processing, no other job can start until the current job is finished executing.
    - example - IBM z/OS
- Multiprogramming Operating Systems - Multiprogramming Operating Systems allow multiple programs to run simultaneously by sharing the CPU and other system resources. These systems quickly switch between programs, giving the appearance that all programs are executing at the same time.
    - example - windows , Linux , OS
- Real-Time Operating Systems - Real-Time Operating Systems (RTOS) are used in time-critical environments where reliability and deadlines are important. They are designed to guarantee a timely response to input events within a specified time frame.
    - example - ROS
- Distributed Operating Systems - Distributed Operating Systems manage resources and coordinate tasks across multiple interconnected computers and nodes. They support distributed file systems, process management, and communication protocols across nodes.
    - hadoop, google file sharing
- Embedded Operating Systems - Embedded Operating Systems are specialized operating systems designed to run on embedded systems, which are computer chips embedded into larger devices or machinery. These systems are resource-constrained and optimized for specific tasks and applications.


> Time sharing ( or multitasking ) CPU executes multiple jobs by switching among them, and the switching is so frequent that user can interact with each of the program while it is running.





### Difference between multiprogramming and multitasking. 


Multiprogramming is a technique where multiple programs are loaded into the computer's memory and the CPU switches between them. It maximizes CPU utilization by keeping it busy with another task when one task is waiting for I/O.

> **The focus is on keeping busy while waiting**, so no time is wasted.

Multitasking is an extension of multiprogramming where multiple tasks or processes are executed seemingly simultaneously by the CPU. The operating system allocates a time slice (short period) to each task so that it appears they are running concurrently.

> **The focus is on giving each task some attention within a set timeframe**, creating the appearance that all tasks are being handled simultaneously.



### System Calls 
provide an interface to the service made available by an operating system. 

> Take an example of copying the content from one file to the other file

### Kernel
The **kernel** is the core component of the operating system that acts as a bridge between the hardware and software layers of a computer system. It is responsible for managing system resources, such as CPU, memory, and Input/Output devices, and providing essential services to run user applications.



There are 2 modes in which the operating system works : 

- user mode - **User Mode** is a restricted execution environment where user applications and processes run. In User Mode, programs have limited access to system resources and cannot perform privileged operations, such as accessing hardware or modifying system settings. The use mode communicates with the kernel / OS by making controlled mechanism called as system call to access resource and privileged operations.
- privileged mode - **Privileged Mode**, also known as Supervisor Mode or Kernel Mode, is an execution environment in which the operating system kernel runs with unrestricted access to system resources. It can perform critical operations like accessing hardware directly, modifying system settings, and managing system memory.
There is a mod bit which specifies OS which mode it is in.

Whenever a user makes a [add the procedure here]



### Process 
- It is an active task on a computer submitted by the user which requires specific resources like CPU, memory etc. It is regarded as the program under execution and can be considered as a unit of work.
> todo: add a diagram of process in memory

It contains 

- Program counter 
- Data section
- Text section
- Stack
- Heap
##### Process state 
**Process Management** involves the activities related to the creation, manipulation, scheduling, and termination of processes in an operating system. 

- New state
- Running state
- Waiting state
- terminate state
- Ready state
### Process control block ( PCB )
The **Process Control Block (PCB)**  is a  data structures used by operating systems to manage processes.

PCBs are created by the operating system when a process starts and are updated throughout its lifetime. They are assigned a unique identifier for distinguishing them from other processes and contain status information indicating if the process is on hold, ready, running, or waiting.

 They contain essential information about the state such as : 

- process state 
- Program counter
- CPU register
- CPU- scheduling algorithm
- Memory management info
- I/O status 
### Threads : 
A thread is a lightweight process that shares the same memory space and resources with other threads within the same process.  each thread has Thread control block same as process. 

It is the smallest unit of  CPU utilization and comprises of 

- thread ID
- program counter
- register set 
- Sack 
- and shares operating system resources like open files code and data section with the other threads of the same process
### Multi threading modes 
- one to one model 
- many to one model
- many to many model
> pthread library is used in linux for the threading operations



#### Scheduling queues 
- job queue - all process in the system
- Ready queue - residing in main memory and ready to move to CPU
- Device queue - for I/0 operations.


> degree of multiprogramming - number of process in main memory



#### Schedulers   
Software that selects the appropriate processes for the available process in  the ready queue and assign it to the CPU.

- short term scheduler 
- long term scheduler 
- medium term scheduler - swapping 


#### Context switching 
> todo: add theory on context switching 





#### Few terms in process 
- process id  (pid)
- fork() - returns pid or 0 based on the child or parent process
- exec() - replace memory place of the child process 
- wait() 
- exit() 
Cascading termination  - If a process terminates then all its children must also terminated. 

Zombie process - A process that has terminated but whose parent has not yet called wait() is known as zombie process. 

Once the parent has called wait() the pid of the zombie process and its entry in the process table are released. 

Orphan process - if the parent did not called wait() there by leaving the child process orphan

### CPU scheduling 
it is the basis of multiprogramming operating system. 

### Preemptive scheduling 
In **Preemptive Scheduling**, the operating system can **interrupt a currently running process** and give the CPU to another process. This can happen if a higher-priority process arrives, a timer indicates the current process's time slice is over, or an event needing immediate attention occurs.

In preemptive scheduling, processes may be **suspended or preempted** even if they haven't voluntarily given up the CPU. The operating system has more control over process execution, which allows it to allocate CPU resources dynamically.

Used in the real time operating system, multiprogramming system and network servers.



### Non-Preemptive Scheduling
In **Non-Preemptive Scheduling**, a running process keeps the CPU until it voluntarily releases it by completing its task, waiting for an I/O operation, or entering a waiting state.

Here, processes are **not interrupted** while executing. They keep control of the CPU until they finish or willingly yield it. 

example : Batch operating system, single user system and resource constrained embedded system.



Few terms: 

- CPU utilization.
- Throughput
- Waiting time
- Turnaround time
- Response time


### Algorithms
Certainly! Here’s the content you provided with added advantages and disadvantages for each scheduling algorithm:

---

#### **FCFS (First-Come, First-Served)**
- In **FCFS scheduling**, processes are executed in the order they arrive in the ready queue. The CPU is allocated to the first process in the queue, and it continues execution until it completes or enters a waiting state.
    - **Advantages:**
        1. **Simple to implement**: Easy to manage and understand since it only requires a queue.
        2. **Fair**: Processes are handled in the order they arrive, ensuring each process is attended without preference.
    - **Disadvantages:**
        1. **Convoy effect**: Longer processes can delay all shorter processes, decreasing overall system efficiency.
        2. **Non-preemptive**: Once a process starts, it runs until it’s done, which can be inefficient for time-sensitive processes.
---

#### **Shortest Job First (SJF)**
- **SJF scheduling** selects the process with the shortest estimated CPU burst time next. This algorithm minimizes the average waiting time by prioritizing short processes.
    - **Advantages:**
        1. **Minimizes average waiting time**: Shorter jobs are processed faster, optimizing system efficiency.
        2. **Efficient for batch jobs**: Ideal for batch processing systems where job length is predictable.
    - **Disadvantages:**
        1. **Starvation of long processes**: Longer jobs can be delayed indefinitely if shorter jobs keep arriving.
        2. **Difficult to estimate burst time**: Predicting the exact CPU time required can be challenging.
---

#### **Shortest Remaining Time First (SRTF)**
- **SRTF** is a preemptive version of SJF where the currently executing process can be preempted by a shorter job. Whenever a new process arrives, the scheduler compares its burst time with the remaining time of the currently executing process and switches if the new process has a shorter remaining time.
    - **Advantages:**
        1. **Minimizes response time**: Shorter processes are prioritized, which improves response time for short tasks.
        2. **Efficient for interactive systems**: Works well in environments where tasks are of varying lengths and require quick response times.
    - **Disadvantages:**
        1. **Higher overhead**: Frequent context switches increase CPU overhead.
        2. **Starvation risk**: Longer processes may experience delays if many shorter jobs arrive continuously.
---

#### **Priority Scheduling**
- In **priority scheduling**, each process has an associated priority, and the CPU is allocated to the process with the highest priority. SJF is a special case of priority scheduling.
    - **Advantages:**
        1. **Flexibility**: Can prioritize critical tasks, which is useful for real-time systems.
        2. **Efficient handling of high-priority tasks**: Allows critical tasks to be executed first, improving response time for important processes.
    - **Disadvantages:**
        1. **Starvation of low-priority processes**: Low-priority tasks may not get CPU time if high-priority tasks keep arriving.
        2. **Complexity of priority assignment**: Determining appropriate priorities can be challenging.
---

#### **Round-Robin (RR)**
- **RR scheduling** allocates CPU time to each process in turn, with a fixed time quantum (also known as a time slice). When a time quantum expires, the currently executing process is preempted, and the CPU is allocated to the next process in the queue.
    - **Advantages:**
        1. **Fairness**: Every process gets an equal time slice, preventing starvation.
        2. **Responsive for interactive systems**: Time-sharing ensures interactive applications are responsive.
    - **Disadvantages:**
        1. **Higher context-switching overhead**: Frequent switches can reduce CPU efficiency.
        2. **Dependent on time quantum selection**: If the time slice is too short or too long, it can reduce efficiency or lead to poor performance.
---

#### **Multilevel Queue**
- **Multilevel queue scheduling** divides the ready queue into multiple queues, each with its own scheduling algorithm and priority level. Processes are assigned to different queues based on criteria such as process type, priority, or characteristics.
    - **Advantages:**
        1. **Separation of process types**: Allows processes with different characteristics to be managed in separate queues, improving efficiency.
        2. **Customization for system requirements**: Different scheduling policies can be applied to each queue for optimized performance.
    - **Disadvantages:**
        1. **Complexity in managing queues**: Coordinating multiple queues with different algorithms increases system complexity.
        2. **Potential starvation**: Processes in lower-priority queues may experience starvation if higher-priority queues are always busy.
---



### Starvation 
- Starvation or indefinite blocking happens when the process is denied with the resources it needs to because the higher priority process are preempted before the lower priority process.
- **Ageing** is a method to prevent starvation by gradually increasing a process's priority as it waits in the queue. This ensures that all processes eventually become high-priority if they wait long enough, allowing them to get their turn for execution.
> **Convoy effect**, where short processes are delayed behind long ones which is especially noticed in the FCFS



### Synchronization
cooperating process - get affected or affect other process running in the system.

Race condition - when several process access and manipulate the same data concurrently and the outcome of the execution depends on the order in which the access take place.

To prevent race conditions, synchronisation mechanisms like locks, mutexes, or other atomic operations are necessary. 

> eg. updating row in the database, bank transaction etc.



### Critical section problem
critical section - a **critical section** is a portion of code that accesses shared resources (such as variables, data structures, or files) which must be accessed by multiple threads or processes.



the problem is to design a protocol so the process can use to cooperate. 

Thre is entry section, exit section and reminder section



Requirements : 

- Mutual exclusion
- Progress
- Bounded waiting
### Mutex locks 
Whe a process wants to enter a critical section, first it has to acquire the lock before entering and release the lock before leaving.



### Semaphores - synchronisation primitives used to manage concurrent processes
- It is an ineger variable that can be accessed only through tow atomic operations that is wait() and signal().
- A semaphore is essentially a variable that signals whether a particular resource is available.
- Types of semaphore 
    - Binary semphore - the value of the integer can be 0 or 1 and is similar to the mutex locks 
    - Counting semaphore - the range of semaphore can be unrestricted and denotes the number of resources available 
### Deadlock 
A **deadlock** is a situation where a set of processes are blocked because each process is holding a resource and waiting for another resource held by another process. 

The conditions for a deadlock to occur include:

- **Mutual Exclusion:** At least one resource must be held in a non-shareable mode.
- **Hold and Wait:** A process must be holding at least one resource while waiting to acquire additional resources.
- **No Preemption:** Resources cannot be forcibly taken from processes until they voluntarily release them.
- **Circular Wait:** A set of processes exists where each process waits for a resource held by the next process in the sequence.
### Classic problem of synchronization 
- The bounded buffer problem 
- Readers writers problem
- Dining philosophers problem


