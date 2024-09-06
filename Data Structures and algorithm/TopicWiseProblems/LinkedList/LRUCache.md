# LRU Cache 
[Problem Link](https://leetcode.com/problems/lru-cache/description/)

## Problem desciption 
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

* LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
* int get(int key) Return the value of the key if the key exists, otherwise return -1.
* void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.


The functions get and put must each run in O(1) average time complexity.


## constraints
* 1 <= capacity <= 3000
* 0 <= key <= 104
* 0 <= value <= 105
* At most 2 * 105 calls will be made to get and put.

### Example 

```bash
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

```

## Code
```cpp
class LRUCache {
public:
    class Node{
        public:
            int key;
            int value;
            Node* prev;
            Node* next;

            Node(int k,int v){
                key = k;
                value = v;
                prev = NULL;
                next = NULL;
            }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> mp;
    int cap;

    LRUCache(int capacity) {
        mp.clear();
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    //Function to delete the node 
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    //funtion to add the node at the head of dll
    void addNodeAtHead(Node* node){
        Node* nodeAfterHead = head->next;
        head->next = node;
        node->next = nodeAfterHead;
        node->prev = head;
        nodeAfterHead->prev = node;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;

        //if the key is present in the cache, then we need to get that node ( delete from the curr position and then append at the starting of the dll )
        /*
            get the node from the map -> it will give yu the address.
            unlink the node from the curr position
            again append it back to the head.
            No need to update the map as no address is changed
        */

        Node* node = mp[key];
        deleteNode(node);
        addNodeAtHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        /*
            If the key is already present in the cache all the thing you need to do is to unlink from curr position and then put that at the front.
            if the key is not alredy present then we have couple of cases
                1. If the size is full, then we need to remove the least used and then add the new one to the front of the dll, 
                2. Else just add to the front of the dll 
        
        */

        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            addNodeAtHead(node);
        }
        else{
            if(mp.size() == cap){
                //getting the least recently used
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
            }

            Node* newNode = new Node(key,value);
            mp[key] = newNode;
            addNodeAtHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

```

## Intuition
This is a heavy implementation problem, where we need to design a LRU Cache. The features of LRU Cache has been given in the problem description. 


In the implementation of an LRU (Least Recently Used) Cache, the use of a doubly linked list (DLL) and an unordered map (or hash map) is crucial for achieving efficient operations. Let's break down the purpose of each data structure:

### 1. **Doubly Linked List (DLL)**

#### Purpose:
The doubly linked list is used to maintain the order of access for the cached elements, allowing us to quickly identify and move the least recently used elements.

#### Key Operations:
- **Order Maintenance**: The DLL maintains the order in which elements were accessed. The head of the list contains the most recently used (MRU) element, and the tail contains the least recently used (LRU) element.
- **Efficient Removal and Addition**:
  - **Adding an Element**: When a new element is accessed or added, it is moved to the front (head) of the list. This operation is \(O(1)\) because it only involves changing a few pointers.
  - **Removing the LRU Element**: When the cache reaches its capacity, the element at the tail (LRU) needs to be removed. This operation is also \(O(1)\) because the DLL allows for efficient removal from the end of the list.

### 2. **Unordered Map (Hash Map)**

#### Purpose:
The unordered map is used to provide fast access to the cache elements by key, enabling quick lookups, inserts, and deletions.

#### Key Operations:
- **Fast Lookup**:
  - **Accessing an Element**: When a cache operation (`get` or `put`) is performed, we need to quickly determine if the element is already in the cache. The hash map provides \(O(1)\) average time complexity for lookups, allowing us to quickly find the corresponding node in the DLL.
- **Tracking Nodes**:
  - The map stores key-value pairs, where the key is the unique identifier for the data, and the value is a pointer to the corresponding node in the DLL. This pointer allows for direct access to the node in the DLL, enabling efficient updates (moving nodes to the front) and deletions.

### **Why Use Both Together?**

The combination of a doubly linked list and an unordered map is powerful because it allows the LRU Cache to meet the following requirements:

- **Fast Access (`get`)**: The unordered map allows you to find an element in \(O(1)\) time. Once found, the corresponding node in the DLL can be accessed directly and moved to the front.
- **Fast Insert and Delete (`put`)**:
  - When inserting a new element, you need to quickly check if the cache is at capacity. If it is, you remove the LRU element (tail node) in \(O(1)\) time using the DLL.
  - The map ensures that new elements can be inserted and old elements can be deleted efficiently, while the DLL maintains the order of usage.


## Approach


## Complexity
- Time complexity: O(1) //as there is only unlinking and linking of the nodes and we are using unordered_map

- Space complexity: O(n) // for map and dll
