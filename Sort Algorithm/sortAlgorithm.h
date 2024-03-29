#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include "../include/printArr.h"

#pragma region 冒泡排序

/// <summary>
/// 冒泡排序
/// </summary>
/// <param name="arr"></param>
void bubbleSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;
  for (int i = 0; i < len - 1; ++i) {
	bool isSwap = false;
	for (int j = 0; j < len - 1 - i; ++j) {
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
void selectionSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;
  for (int i = 0; i < len - 1; ++i) {
	int minIndex = i;
	for (int j = i + 1; j < len; ++j) {
	  if (nums[j] < nums[minIndex]) minIndex = j;
	}
	if (minIndex != i) {
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
void insertSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len <= 1) return;
  for (int i = 1; i < len; ++i) {
	for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; --j) {
	  std::swap(nums[j], nums[j + 1]);
	}
  }
//  for (int i = 1; i < len; ++i) {
//	int insertVal = nums[i];
//	int insertIndex = i - 1;
//	while (insertIndex >= 0 && insertVal < nums[insertIndex]) {
//	  nums[insertIndex + 1] = nums[insertIndex];
//	  --insertIndex;
//	}
//	nums[insertIndex + 1] = insertVal;
//  }
}

#pragma endregion

#pragma region 希尔排序-移动法

/// <summary>
/// 希尔排序-移动法
/// </summary>
/// <param name="nums"></param>
void shellSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len <= 1) return;
  for (int gap = len / 2; gap > 0; gap /= 2) {
	for (int i = gap; i < len; ++i) {
	  int index = i;
	  int temp = nums[i];
	  while (index - gap >= 0 && temp < nums[index - gap]) {
		nums[index] = nums[index - gap];
		index -= gap;
	  }
	  nums[index] = temp;
	}
  }
}

#pragma endregion

#pragma region 快速排序

// 返回等于区的左右边界
std::pair<int, int> partition(std::vector<int> &nums, int l, int r) {
  int lt = l - 1; //小于区的右边界
  int gt = r;     //大于区的左边界
  while (l < gt) { //l表示当前数所在位置，以nums[r]为划分值
	if (nums[l] < nums[r]) {
	  std::swap(nums[++lt], nums[l++]);
	} else if (nums[l] > nums[r]) {
	  std::swap(nums[--gt], nums[l]);
	} else {
	  l++;
	}
  }
  std::swap(nums[l], nums[r]);
  return {lt + 1, gt};
}

void quickSortSub(std::vector<int> &nums, int l, int r) {
  if (l < r) {
	std::swap(nums[rand() % (r - l + 1) + l], nums[r]);
	auto p = partition(nums, l, r);
	quickSortSub(nums, l, p.first - 1);
	quickSortSub(nums, p.second + 1, r);
  }
}

/// <summary>
/// 快速排序
/// </summary>
/// <param name="nums"></param>
void quickSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;
  quickSortSub(nums, 0, len - 1);
}

#pragma endregion
//#pragma region 快速排序
//
//void quickSortSub(std::vector<int> &nums, int left, int right) {
//  if (left > right) return;
//  int base = nums[left];
//  int i = left, j = right;
//  while (i != j) {
//	while (nums[j] >= base && i < j) --j;
//	while (nums[i] <= base && i < j) ++i;
//	if (i < j) {
//	  std::swap(nums[i], nums[j]);
//	}
//  }
//  // 将基准数放到中间的位置（基准数归位）
//  nums[left] = nums[i];
//  nums[i] = base;
//
//  quickSortSub(nums, left, i - 1);
//  quickSortSub(nums, i + 1, right);
//}
//
///// <summary>
///// 快速排序
///// </summary>
///// <param name="nums"></param>
//void quickSort(std::vector<int> &nums) {
//  int len = nums.size();
//  if (len < 2) return;
//  quickSortSub(nums, 0, len - 1);
//}
//
//#pragma endregion

#pragma region 归并排序

void merge(std::vector<int> &nums, int left, int mid, int right) {
  std::vector<int> temp{};
  int i = left, j = mid + 1;
  while (i <= mid && j <= right) {
	int num = nums[i] < nums[j] ? nums[i++] : nums[j++];
	temp.push_back(num);
  }
  while (i <= mid) temp.push_back(nums[i++]);
  while (j <= right) temp.push_back(nums[j++]);
  for (int m = 0; m < temp.size(); ++m) {
	nums[left + m] = temp[m];
  }
}

void process(std::vector<int> &nums, int left, int right) {
  int mid = (left + right) / 2;
  if (left < right) {
	process(nums, left, mid);
	process(nums, mid + 1, right);
	merge(nums, left, mid, right);
  }
}

/// <summary>
/// 归并排序
/// </summary>
/// <param name="nums"></param>
void mergeSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;
  process(nums, 0, len - 1);
}

#pragma endregion

#pragma region 基数排序

/**
 * 求数据的最大位数,决定排序次数
 * @param nums
 * @return
 */
int maxBit(std::vector<int> &nums) {
  int maxNum = 0;
  for (int i = 0; i < nums.size(); i++) {
	maxNum = std::max(maxNum, nums[i]);
  }
  int digits = 0;
  while (maxNum > 0) {
	digits++;
	maxNum /= 10;
  }
  return digits;
}

/// <summary>
/// 基数排序
/// </summary>
/// <param name="nums"></param>
void radixSort(std::vector<int> &nums) {
  int d = maxBit(nums), len = nums.size();
  std::vector<int> tmp(len);
  int radix = 1;
  for (int i = 1; i <= d; i++) { //进行d次排序
	int t = 0;
	for (int j = 0; j < 10; j++) { //按数位从小到大插进桶中
	  for (int k = 0; k < len; k++) {
		if (nums[k] / radix % 10 == j) {
		  tmp[t++] = nums[k];
		}
	  }
	  if (t == len) break;
	}
	nums = tmp; //将临时数组的内容复制回去
	radix *= 10;
  }
}

#pragma endregion

#pragma region 堆排序

// 在start 和end区间内，如果父节点小于子节点，就交换
void heapify(std::vector<int> &nums, int start, int end) {
  int root = start;
  int child = 2 * root + 1; //左子节点
  while (child < end) {                                                  // 若子节点指标在范围内才做比较
	if (child + 1 <= end && nums[child] < nums[child + 1]) ++child;   //先比较两个子节点大小，选择最大的
	if (nums[child] <= nums[root]) return;                            //如果父节点大于子节点代表调整完毕，直接跳出函数
	std::swap(nums[root], nums[child]);                                  //否则交换父子内容再继续子节点和孙节点比较
	root = child;
	child = 2 * root + 1;
  }
}

/// <summary>
/// 堆排序
/// </summary>
/// <param name="nums"></param>
void heapSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;

  // 初始化，i从最后一个父节点开始调整
  // 堆数组的前一半为父节点，后一半为子节点
  for (int i = len / 2 - 1; i >= 0; --i) {
	heapify(nums, i, len - 1);
  }

  //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
  for (int j = len - 1; j > 0; --j) {
	std::swap(nums[0], nums[j]);
	heapify(nums, 0, j - 1);
  }
}

#pragma endregion

#endif


