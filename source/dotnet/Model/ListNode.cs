using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class ListNode
    {
        public int Value { get; init; }
        public ListNode Next { get; set; }

        public ListNode(int value)
        {
            Value = value;
        }
    }
}