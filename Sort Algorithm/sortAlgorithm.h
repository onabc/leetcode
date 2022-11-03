#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include "../include/printArr.h"

#pragma region 冒泡排序
/// <summary>
/// 冒泡排序
/// </summary>
/// <param name="arr"></param>
void bubbleSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len < 2) return;
	for (int i = 0; i < len - 1; ++i)
	{
		bool isSwap = false;
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (nums[j] <= nums[j + 1]) continue;
			std::swap(nums[j], nums[j + 1]);
			isSwap = true;
		}
		if (!isSwap) return;
	}
}
#pragma endregion 

#pragma region 选择排序
/// <summary>
/// 选择排序
/// </summary>
/// <param name="nums"></param>
void selectionSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len < 2) return;
	for (int i = 0; i < len - 1; ++i)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (nums[j] < nums[minIndex]) minIndex = j;
		}
		if (minIndex != i)
		{
			std::swap(nums[minIndex], nums[i]);
		}
	}
}
#pragma endregion 

#pragma region 插入排序
/// <summary>
/// 插入排序
/// </summary>
/// <param name="nums"></param>
void insertSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len <= 1) return;
	for (int i = 1; i < len; ++i)
	{
		int insertVal = nums[i];
		int insertIndex = i - 1;
		while (insertIndex >= 0 && insertVal < nums[insertIndex])
		{
			nums[insertIndex + 1] = nums[insertIndex];
			--insertIndex;
		}
		nums[insertIndex + 1] = insertVal;
	}
}
#pragma endregion 

#pragma region 希尔排序-移动法
/// <summary>
/// 希尔排序-移动法
/// </summary>
/// <param name="nums"></param>
void shellSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len <= 1) return;
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < len; ++i)
		{
			int index = i;
			int temp = nums[i];
			while (index - gap >= 0 && temp < nums[index - gap])
			{
				nums[index] = nums[index - gap];
				index -= gap;
			}
			nums[index] = temp;
		}
	}
}
#pragma endregion 

#pragma region 快速排序
void quickSortSub(std::vector<int>& nums, int left, int right)
{
	if (left > right) return;
	int base = nums[left];
	int i = left, j = right;
	while (i != j)
	{
		while (nums[j] >= base && i < j) --j;
		while (nums[i] <= base && i < j) ++i;
		if (i < j)
		{
			std::swap(nums[i], nums[j]);
		}
	}
	// 将基准数放到中间的位置（基准数归位）
	nums[left] = nums[i];
	nums[i] = base;

	quickSortSub(nums, left, i - 1);
	quickSortSub(nums, i + 1, right);
}
/// <summary>
/// 快速排序
/// </summary>
/// <param name="nums"></param>
void quickSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len < 2) return;
	quickSortSub(nums, 0, len - 1);
}
#pragma endregion 

#pragma region 归并排序
void merge(std::vector<int>& nums, int left, int mid, int right)
{
	std::vector<int> temp{};
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		int num = nums[i] < nums[j] ? nums[i++] : nums[j++];
		temp.push_back(num);
	}
	while (i <= mid) temp.push_back(nums[i++]);
	while (j <= right) temp.push_back(nums[j++]);
	for (int m = 0; m < temp.size(); ++m)
	{
		nums[left + m] = temp[m];
	}
}
void mergeSort(std::vector<int>& nums, int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}
/// <summary>
/// 归并排序
/// </summary>
/// <param name="nums"></param>
void mergeSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len < 2) return;
	mergeSort(nums, 0, len - 1);
}
#pragma endregion 

#pragma region 基数排序
/// <summary>
/// 基数排序
/// </summary>
/// <param name="nums"></param>
void radixSort(std::vector<int>& nums)
{
}
#pragma endregion 

#pragma region 堆排序
void heapAdjust(std::vector<int>& nums, int start, int end)
{
	int root = start;
	int child = 2 * root + 1;
	while (child < end)
	{
		if (child + 1 <= end && nums[child] < nums[child + 1]) ++child;
		if (nums[child] <= nums[root]) return;
		std::swap(nums[root], nums[child]);
		root = child;
		child = 2 * root + 1;
	}
}
/// <summary>
/// 堆排序
/// </summary>
/// <param name="nums"></param>
void heapSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len < 2) return;
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		heapAdjust(nums, i, len - 1);
	}

	for (int j = len - 1; j > 0; --j)
	{
		std::swap(nums[0], nums[j]);
		heapAdjust(nums, 0, j - 1);
	}
}
#pragma endregion 

#endif


