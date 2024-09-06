# Remove Nth node from the end 
[Problem Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

## Problem desciption 
Given the head of a linked list, remove the nth node from the end of the list and return its head.

### Example 1
> Input: head = [1,2,3,4,5], n = 2<br>
> Output: [1,2,3,5]<br>

### Example 2:

> Input: head = [1], n = 1<br>
> Output: []<br>


### Example 3:

> Input: head = [1,2], n = 1<br>
> Output: [1]<br>

## constraints
* The number of nodes in the list is sz.
* 1 <= sz <= 30
* 0 <= Node.val <= 100
* 1 <= n <= sz

## Code

In two pass 

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;
        while(curr){
            length++;
            curr=curr->next;
        }
        curr = head;
        ListNode* prev = head;
        if(n==length){
            head = head->next;
            return head;
        }
        for(int i=1;i<=(length-n);i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
        
    }
};
```

In single pass - using fast and slow pointer 

``` cpp

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow  = head;
        ListNode* fast = head;

        for(int i=1;i<=n;i++){
            fast = fast->next;
        }

        if(fast == NULL) return head->next;

        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};

```

## Intuition
The naive approach would be to traverse the entire length first to find the lenght, then move n - l -1 times and delete the node, be cautions about the edge cases ie. removing the first node when the n is length.

The optimised approach would be to use two pointers fast and slow pointers, move the fast pointer k length and then move both of the pointer untill it reaches the last node. Here too, there exist a condition where we need to delete the first node, handle that case as mentioned above. then the slow pointer would be pointing to the node before the node to be deleted. 



## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
