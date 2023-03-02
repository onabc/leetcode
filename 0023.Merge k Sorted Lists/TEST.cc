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

TEST_CASE("Merge K Sorted Lists", "[mergeKLists]")
{
    Solution s;
    vector<int> result;
    ListNode *list1 = create_linkedlist({1, 4, 5});
    ListNode *list2 = create_linkedlist({1, 3, 4});
    ListNode *list3 = create_linkedlist({2, 6});

    ListNode *ret = s.mergeKLists(vector<ListNode *>{list1, list2, list3});
    for (ListNode *cur = ret; cur; cur = cur->next)
        result.push_back(cur->val);

    REQUIRE((result == vector<int>{1, 1, 2, 3, 4, 4, 5, 6}));
}