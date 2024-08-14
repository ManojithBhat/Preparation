# Add Two Numbers
[Problem Link](https://leetcode.com/problems/add-two-numbers/description/)

## Problem desciption 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

### Example 1
> **Input:** l1 = [9,9,9,9,9,9,9], <br>l2 = [9,9,9,9]<br>
> **Output:** [8,9,9,9,0,0,0,1]

> **Input:** l1 = [2,4,3], l2 = [5,6,4]<br>
> **Output:** [7,0,8]<br>
> **Explanation:** 342 + 465 = 807.<br>

## constraints
* The number of nodes in each linked list is in the range [1, * 100].
* 0 <= Node.val <= 9
* It is guaranteed that the list represents a number that does not have leading zeros.

## Code
```cpp

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(-1),*head = curr;

        int carry = 0;
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            carry = sum/10;
        }
        return head->next;
    }
};

```
[Add linked list 2](https://leetcode.com/problems/add-two-numbers-ii/) 

```cpp
class Solution {
public:
    ListNode* reverse(ListNode* curr){
        ListNode* prev = NULL;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(-1),*head = curr;

        if(!l1) return l2;
        if(!l2) return l1;
 
        l1 = reverse(l1);
        l2 = reverse(l2);

        int carry = 0;
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            carry = sum/10;
        }
        curr = reverse(head->next);
        return curr;
    }
};

```

## Intuition
The key thing to note is the linked list is already given in the reverse order and  we need to return the answer in the reverse order, if it was not given we have to use reverse function to reverse the linked list. ( the code for this has also been updated).

The key thing to note in the problem is we need a carry and sum variable and we need to iterate till ``` carry or l1 or l2 ``` is exhausted. and construct the node for every digit sum calculated by ``` digit1 + digit2 + carry and sum%10 ``` and carry equal to ```sum/10```


## Complexity 
- Time complexity: O(max(n1,n2))


- Space complexity: O(max(n1,n2))
