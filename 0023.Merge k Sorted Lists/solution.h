#include <queue>
#include "../include/ListNode.h"

using namespace std;

class Solution {
  struct comparator {
	bool operator()(ListNode *l1, ListNode *l2) {
	  return l1->val > l2->val;
	}
  };

  priority_queue<ListNode *, vector<ListNode *>, comparator> q;
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
	ListNode *head = new ListNode();
	ListNode *tail = head;
	for (ListNode *list : lists) {
	  if (list) q.push(list);
	}
	while (!q.empty()) {
	  ListNode *node = q.top();
	  q.pop();
	  tail->next = node;
	  tail = tail->next;
	  if (node->next) q.push(node->next);
	}
	return head->next;
  }
  //public:
  //    ListNode* mergeKLists(vector<ListNode*>& lists) {
  //        if (lists.empty()) return NULL;
  //        ListNode* ans = nullptr;
  //        for (int i = 0; i < lists.size(); ++i) {
  //            ans = mergeTwoLists(ans, lists[i]);
  //        }
  //        return ans;
  //    }
  //
  //    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  //        if (!l1) return l2;
  //        if (!l2) return l1;
  //
  //        if (l1->val < l2->val) {
  //            l1->next = mergeTwoLists(l1->next, l2);
  //            return l1;
  //        }
  //        else {
  //            l2->next = mergeTwoLists(l2->next, l1);
  //            return l2;
  //        }
  //    }
};