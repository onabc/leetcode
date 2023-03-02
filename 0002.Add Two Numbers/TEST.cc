#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "solution.h"

using namespace std;
using Catch::Matchers::Equals;

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

TEST_CASE("Add Two Numbers", "[addTwoNumbers]")
{
    Solution s;
    vector<int> result;

    ListNode *l1 = create_linkedlist({2, 4, 3});
    ListNode *l2 = create_linkedlist({5, 6, 4});
    ListNode *ret = s.addTwoNumbers(l1, l2);
    for (ListNode *cur = ret; cur; cur = cur->next)
        result.push_back(cur->val);

    CHECK_THAT(result, Equals(vector<int>{7, 0, 8}));
}