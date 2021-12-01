#include <array>
#include <vector>
#include <string>
#include "../include/ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** del = &head, * iter = head;
        for (int i = 0; i < n; i++) {
            iter = iter->next;
        }
        while (iter != NULL)
        {
            del = &((*del)->next);
            iter = iter->next;
        }
        *del = (*del)->next;
        return head;
    }
};