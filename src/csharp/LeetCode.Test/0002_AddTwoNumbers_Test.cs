using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Test
{
    [TestFixture]
    internal class AddTwoNumbers_Test
    {
        private ListNode l1;
        private ListNode l2;

        [SetUp]
        public void Setup()
        {
            var node1 = new ListNode(9);
            var node2 = new ListNode(4);
            var node3 = new ListNode(7);
            var node4 = new ListNode(2);

            l1 = new ListNode(3);
            l2 = new ListNode(5);

            l1.Next = node1;
            node1.Next = node2;

            l2.Next = node3;
            node3.Next = node4;
        }

        [Test]
        public void AddTwoNumbersTest()
        {
            ListNode node = AddTwoNumbersClass.AddTwoNumbers(l1, l2);
            int[] expectation = new int[] { 8, 6, 7 };

            List<int> list = new List<int>();
            while (node != null)
            {
                list.Add(node.Value);
                node = node.Next;
            }
            int[] result = list.ToArray();
            bool isEqual = Enumerable.SequenceEqual(result, expectation);
            Assert.IsTrue(isEqual);
        }
    }
}