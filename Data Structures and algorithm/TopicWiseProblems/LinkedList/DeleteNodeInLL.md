# Delete a node in LinkedList
[Problem Link](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)

## Problem desciption 



## constraints


## Code
```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node->next){
            prev = node;
            node->val = node->next->val;
            node = node->next;
        }
        prev->next = NULL;
        delete node;
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
