from typing import List


def twoSum(nums: List[int], target: int) -> List[int]:
    """
    两数之和
    :param self:
    :param nums:
    :param target:
    :return:
    """
    dic = {}
    for index, num in enumerate(nums):
        if num in dic:
            return [dic[num], index]
        dic[target - num] = index

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    assert (twoSum(nums, target) == [0, 1])