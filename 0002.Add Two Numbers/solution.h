#include "../include/ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;

        cur->next = new ListNode(sum % 10);
        cur = cur->next;

        carry = sum / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy->next;
}