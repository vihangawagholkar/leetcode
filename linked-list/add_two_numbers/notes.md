Here’s a clean notes.md you can put in your repo for the Add Two Numbers problem. Keep it short and focused on the idea and pattern.

# Add Two Numbers

## Problem
You are given two non-empty linked lists representing two non-negative integers.  
The digits are stored in reverse order, and each node contains a single digit.  

Add the two numbers and return the sum as a linked list.

Example:

Input:
l1 = [2,4,3]  
l2 = [5,6,4]

Output:
[7,0,8]

Explanation:
342 + 465 = 807

---

## Key Idea

We simulate **digit-by-digit addition**, just like elementary addition.

At each node:

sum = digit1 + digit2 + carry

We store:

digit = sum % 10  
carry = sum / 10

---

## Approach

1. Create a **dummy node** to simplify list construction.
2. Traverse both lists simultaneously.
3. If a list ends, treat its value as **0**.
4. Compute the sum and update carry.
5. Create a new node with `sum % 10`.
6. Move forward until both lists and carry are exhausted.

---

## Code Pattern

```cpp
ListNode* dummy = new ListNode(0);
ListNode* curr = dummy;

while(l1 || l2 || carry){
    int x = l1 ? l1->val : 0;
    int y = l2 ? l2->val : 0;

    int sum = x + y + carry;

    carry = sum / 10;

    curr->next = new ListNode(sum % 10);
    curr = curr->next;

    if(l1) l1 = l1->next;
    if(l2) l2 = l2->next;
}

return dummy->next;


⸻

Complexity

Time Complexity:

O(max(n, m))

We traverse each list once.

Space Complexity:

O(max(n, m))

For the resulting linked list.

⸻

Key Pattern Learned

Dummy Node Linked List Construction

Used in many problems like:
	•	Merge Two Sorted Lists
	•	Remove Nth Node From End
	•	Reverse Linked List II

Pattern:

ListNode* dummy = new ListNode(0);
ListNode* curr = dummy;

curr->next = new ListNode(value);
curr = curr->next;

return dummy->next;


⸻

Mistakes I Made
	•	Dereferencing nullptr (l1->val when l1 == nullptr)
	•	Forgetting to handle carry
	•	Not moving curr forward
	•	Returning the dummy node instead of dummy->next

⸻

Takeaway

This problem teaches how to:
	•	Traverse linked lists safely
	•	Manage carry in digit addition
	•	Build a new linked list using the dummy node pattern

