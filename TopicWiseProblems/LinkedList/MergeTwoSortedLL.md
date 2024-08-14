# Merge Two Sorted Linked List
[Problem Link](https://leetcode.com/problems/merge-two-sorted-lists/description/)

## Problem desciption 
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

### Example 1
> **Input:** list1 = [1,2,4], list2 = [1,3,4]<br>
> **Output:** [1,1,2,3,4,4]

## constraints
* The number of nodes in both lists is in the range [0, 50].
* -100 <= Node.val <= 100
* Both list1 and list2 are sorted in non-decreasing order.

## Code
```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(-1),*head = temp;

        if(!list1) return list2;
        if(!list2) return list1;
        
        while(list1 && list2){
            
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp=temp->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
                temp=temp->next;
            }
            
        }   

        if(list1){
            temp->next = list1;
        }

        if(list2){
            temp->next = list2;
        }

        return head->next;
    }
};

```

## Intuition
*Brute Force* <br>
The brute force approach is to create a array to store the the elements of the linked list, we need to traverse through  both the arrays, store them into the array, sort into and then convert to linked list again. 
<br>
The time complexity of this would be O(n1 + n2)<br>
The space complexity would be O(n1+n2) as we need to make an array and ll 

The optimal approach would be to reuse the given nodes.
> Whenver there is a question to reuse the nodes, we have to create a dummy node and use it.
<br>

We keep two pointer and a dummy node, and go until one of them is null, we keep relinking the nodes based on the value, please not on the if condition check inside the while loop ( it is not both if , it is if-else ). And whenever there is remaining list, just append it.


## Complexity
- Time complexity: O(max(n1,n2))

- Space complexity: O(1)
