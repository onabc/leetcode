using NUnit.Framework;
using System;
using System.Linq;

namespace LeetCode.Test
{
    public class TwoSum_Test
    {
        private int[] nums;
        private int target;

        [SetUp]
        public void Setup()
        {
            nums = new int[] { 1, 3, 5, 7, 9, 4 };
            target = 9;
        }

        [Test]
        public void TwoSumTest()
        {
            int[] result = TwoSumClass.TwoSum(nums, target);
            int[] expectation = new int[] { 2, 5 };
            bool isEqual = Enumerable.SequenceEqual(result, expectation);
            Assert.IsTrue(isEqual);
        }
    }
}