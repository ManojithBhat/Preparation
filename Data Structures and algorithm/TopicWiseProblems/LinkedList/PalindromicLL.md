# Palindromic Linked List
[Problem Link](https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1)

## Problem desciption 
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

### Example 1
> **Input:** LinkedList: 1->2->1->1->2->1<br>
> **Output:** true<br>
> **Explanation:** The given linked list is 1->2->1->1->2->1 , > which is a palindrome and Hence, the output is true.
> 
## constraints
* 1 <= number of nodes <= 105
* 1 ≤ node->data ≤ 103

## Code
```cpp

class Solution {
  public:
  Node* reverse(Node* head){
      Node* prev = NULL, *curr = head;
      while(curr!=NULL){
         Node* nxt = curr->next;
         curr->next = prev;
         prev = curr;
         curr = nxt;
      }
      return prev;
  }
  
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Place the sow and fast pointer at the first position 
        if(head->next==NULL) return true;
        Node* slow = head, *fast = head;
        
        while(fast->next && fast->next->next){
            //fast->next condition is applicable for odd length ll and next one is for even length 
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //the slow is not pointing to the point next from where we have to reverse the lined list 
        slow->next = reverse(slow->next);
        //point slow to the new reversed ll 
        slow = slow->next;
        
        while(slow){
            if(head->data != slow->data) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};

```

## Intuition
### Theory Behind the Program

The goal of this program is to check if a singly linked list is a **palindrome**, meaning the sequence of nodes is the same when read forward or backward.

#### Key Concepts:

1. **Two-pointer technique (slow and fast pointers)**:
   - To efficiently find the **middle** of the linked list, we use two pointers:
     - **Slow pointer**: Moves one step at a time.
     - **Fast pointer**: Moves two steps at a time.
   - By the time the fast pointer reaches the end of the list, the slow pointer will be at the **middle**. This works because the fast pointer traverses the list twice as fast as the slow pointer.

2. **Reversing the second half**:
   - Once we find the middle, the second half of the list is **reversed**. This step is necessary because to check if the list is a palindrome, we need to compare the first half with the reversed second half.
   - Reversing the second half allows us to traverse both halves **simultaneously** from the middle outward.

3. **Comparing the halves**:
   - After reversing the second half, we compare the elements of the first half (from the head of the list to the middle) with the elements of the second half (from the middle to the end).
   - If all corresponding elements match, the linked list is a **palindrome**. If any element differs, the list is **not a palindrome**.

#### Detailed Explanation of Key Steps:

1. **Middle Detection**:
   - Using the slow and fast pointers, we efficiently locate the middle of the list. If the list has an odd number of elements, the slow pointer will point exactly to the middle. If it has an even number, the slow pointer will point to the last node of the first half.
   
2. **Reversing the Second Half**:
   - The second half of the list (starting from the node right after the slow pointer) is reversed. Reversing helps in comparing the two halves directly, as we can now start from both ends of the list and move toward the center.
   
3. **Comparison**:
   - After reversing, the list is effectively split into two parts: the first half and the reversed second half. We then compare the values of nodes from both parts to check if they match. If all values match, the list is a palindrome.

By following these steps, we can determine if the given linked list has palindrome-like symmetry in an efficient manner, with a time complexity of **O(n)** and a space complexity of **O(1)**.


## Approach


## Complexity
- Time complexity:


- Space complexity:
