

/*

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

*/ 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //hare and tortise method 
        ListNode* fast = head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};


/*
This problem is solved by the hare and tortise method. where there exist 2 pointes hare and tortise. when the hare moves 2 steps the tortise moves 1 step. so when the hare reaches the end of the linked list the tortise will be at the middle of the linked list. so by this method we can find the middle element of the linked list.


pitfall : in the while loop fast should be checked first and then fast->next should be checked. if we check fast->next first then it will throw an error as fast->next->next will be checked when fast is null.

Time Complexity : O(N) as we are traversing the linked list only once.
Space Complexity : O(1) as we are not using any extra space.
 */