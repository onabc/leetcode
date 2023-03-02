#include <array>
#include <vector>
#include <string>
#include "../include/ListNode.h"

using namespace std;

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *dummy = new ListNode(-1, head);
	ListNode *fast = dummy, *slow = dummy;
	while (n--) fast = fast->next;
	while (fast->next) {
	  fast = fast->next;
	  slow = slow->next;
	}
	slow->next = slow->next->next;
	return dummy->next;
  }
};