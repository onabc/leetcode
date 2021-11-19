using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public static class TwoSumClass
    {
        public static int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> dic = new();
            for (int i = 0; i < nums.Length; i++)
            {
                int temp = target - nums[i];
                if (dic.ContainsKey(temp))
                {
                    return new int[] { dic[temp], i };
                }
                else
                {
                    dic.Add(nums[i], i);
                }
            }

            return new int[0];
        }
    }
}