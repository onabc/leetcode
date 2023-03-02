#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

ListNode *create_linkedlist(initializer_list<int> lst) {
    auto iter = lst.begin();
    ListNode *head = nullptr;
    if (lst.size()) {
        head = new ListNode(*iter++);
        for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
            cur->next = new ListNode(*iter++);
    }
    return head;
}

TEST_CASE("Merge Two Sorted Lists", "[mergeTwoLists]")
{
    Solution s;
    vector<int> result;
    ListNode *list1 = create_linkedlist({1, 2, 4});
    ListNode *list2 = create_linkedlist({1, 3, 4});

    ListNode *ret = s.mergeTwoLists(list1, list2);
    for (ListNode *cur = ret; cur; cur = cur->next)
        result.push_back(cur->val);

    REQUIRE((result == vector<int>{1, 1, 2, 3, 4, 4}));
}