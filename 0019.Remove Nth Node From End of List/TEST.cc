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

TEST_CASE("Remove Nth Node From End of List", "[removeNthFromEnd]")
{
  Solution s;
  vector<int> result;

  ListNode *list = create_linkedlist({1, 2, 3, 4, 5});
  ListNode *ret = s.removeNthFromEnd(list, 2);
  for (ListNode *cur = ret; cur; cur = cur->next)
	result.push_back(cur->val);

  REQUIRE((result == vector<int>{1, 2, 3, 5}));
}