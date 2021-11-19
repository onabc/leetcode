using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public static class AddTwoNumbersClass
    {
        public static ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode head = null, tail = null;
            int carry = 0;

            while (l1 != null || l2 != null)
            {
                int val1 = l1?.Value ?? 0;
                int val2 = l2?.Value ?? 0;
                int sum = val1 + val2 + carry;

                if (head is null)
                {
                    head = tail = new ListNode(sum % 10);
                }
                else
                {
                    tail.Next = new ListNode(sum % 10);
                    tail = tail.Next;
                }

                carry = sum / 10;

                if (l1 != null)
                {
                    l1 = l1.Next;
                }
                if (l2 != null)
                {
                    l2 = l2.Next;
                }
            }
            if (carry > 0)
            {
                tail.Next = new ListNode(carry);
            }
            return head;
        }
    }
}