# Copy List with random pointers
[Problem Link]()

## Problem desciption 

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

### Example 1
>**Input:** head = [[7,null],[13,0],[11,4],[10,2],[1,0]]<br>
**Output:** [[7,null],[13,0],[11,4],[10,2],[1,0]]

## constraints
* 0 <= n <= 1000
* -104 <= Node.val <= 104
* Node.random is null or is pointing to some node in the linked list.

## Code
Approcah 1 with map

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //better approach.
        unordered_map<Node*,Node*> mp;
        Node* curr = head;

        //create a deep copy with only data without the connections / ptrs
        while(curr){
            Node* copyNode = new Node(curr->val);
            mp[curr] = copyNode;
            curr = curr->next;
        }

        Node* dummy = new Node(-1);
        Node* tmp = dummy;
        curr = head;
        tmp->next = mp[curr];
        while(curr){
            Node* copyNode = mp[curr];
            copyNode->next = mp[curr->next];
            copyNode->random = mp[curr->random];
            curr = curr->next;
            tmp = tmp->next; 
        }

        return dummy->next;
    }
};
```
```cpp

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        // Step 1: Create new nodes and interweave them with the original list
        Node* current = head;
        while (current != nullptr) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Step 2: Set the random pointers for new nodes
        current = head;
        while (current != nullptr) {
            Node* copy = current->next;
            copy->random = (current->random != nullptr) ? current->random->next : nullptr;
            current = copy->next;
        }

        // Step 3: Separate the original and copy lists
        Node* original = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;
        while (original != nullptr) {
            original->next = copy->next;
            original = original->next;

            if (original != nullptr) {
                copy->next = original->next;
                copy = copy->next;
            }
        }

        copy->next = nullptr;
        return copyHead;
    }
};


``

## Intuition
What is a Deep Copy?

In simple words , a deep copy is a complete copy For instance , we have a block A that has a memory location of , say 0x12WE . Now when I say a deep copy of this block A , this actually means creating a copy block A' with a different address block .
A deep copy is a complete and independent copy of an object.

need to do in 2 passes, one time we create deap copy of the only the nodes without the links, and next we try to add the links for new node corresponding to the old nodes in the map.

The other approach included, addign new nodes after the curr node and using 2 loops to create the random pointer once and other too delink.

## Approach


## Complexity
- Time complexity:


- Space complexity:
