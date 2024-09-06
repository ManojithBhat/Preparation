/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // if(head==NULL) return 0;
        if(head==NULL || head->next==NULL) return 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return 1;
            }
        }
        return 0;
    }
};


/*

Intution : Floyd's cycle detection algorithm - hare and tortise method
    In this method we will be using 2 pointers hare and tortise. hare will move 2 steps and tortise will move 1 step. if there is a cycle in the linked list then the hare and tortise will meet at some point. if there is no cycle then the hare will reach the end of the linked list.
    so by this method we can detect the cycle in the linked list.
    the reason this works because the hare moves 2 steps and the tortise moves 1 step. so when the hare reaches the end of the linked list the tortise will be at the middle of the linked list. so if there is a cycle then the hare and tortise will meet at some point.

    time complexity : O(N) as we are traversing the linked list only once.
    space complexity : O(1) as we are not using any extra space.


*/