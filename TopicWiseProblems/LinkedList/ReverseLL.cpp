

/*

Given the head of a singly linked list, reverse the list, and return the reversed list.


Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr!=NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};


/*

//brute force - traverse the ll and store the elements in the array, and then reverse the array and create the new LL
//time complexity : O(N) + O(N) + O(N) = O(N)
//space complexity : O(N) as we are using the array to store the elements of the linked list.

Intution : 
    In this problem we are given a linked list and we need to reverse the linked list. so the first thing that comes to mind is to use the iterative approach. we will be using 3 pointers prev, curr and nxt. we will be traversing the linked list and at each node we will be reversing the link of the current node to the previous node. so by this method we can reverse the linked list, the purpose of using the next pointer is that we dont loose the next node of the current node. 

    time complexity : O(N) as we are traversing the linked list only once.
    space complexity : O(1) as we are not using any extra space.
*/