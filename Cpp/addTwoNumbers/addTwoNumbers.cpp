// URL: https://leetcode.com/problems/add-two-numbers/
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a node before the head so that we don't have to have to rewrite code
        // If we didn't have the node before the head we would need to run through the code once to receive the root and
        // then in a loop have the code written again
        ListNode prehead(0);
        // Create a pointer to the address 
        ListNode* p = &prehead;
        int carry = 0;
        // while(l1 != NULL, l2 != NULL, carry != 0)
        while(l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            p->next = node;
            p = node;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return prehead.next;
    }
};
