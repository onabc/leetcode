#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include "../include/printArr.h"

#pragma region ð������

/// <summary>
/// ð������
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

#pragma region ѡ������

/// <summary>
/// ѡ������
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

#pragma region ��������

/// <summary>
/// ��������
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

#pragma region ϣ������-�ƶ���

/// <summary>
/// ϣ������-�ƶ���
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

#pragma region ��������

// ���ص����������ұ߽�
std::pair<int, int> partition(std::vector<int> &nums, int l, int r) {
  int lt = l - 1; //С�������ұ߽�
  int gt = r;     //����������߽�
  while (l < gt) { //l��ʾ��ǰ������λ�ã���nums[r]Ϊ����ֵ
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
/// ��������
/// </summary>
/// <param name="nums"></param>
void quickSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;
  quickSortSub(nums, 0, len - 1);
}

#pragma endregion
//#pragma region ��������
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
//  // ����׼���ŵ��м��λ�ã���׼����λ��
//  nums[left] = nums[i];
//  nums[i] = base;
//
//  quickSortSub(nums, left, i - 1);
//  quickSortSub(nums, i + 1, right);
//}
//
///// <summary>
///// ��������
///// </summary>
///// <param name="nums"></param>
//void quickSort(std::vector<int> &nums) {
//  int len = nums.size();
//  if (len < 2) return;
//  quickSortSub(nums, 0, len - 1);
//}
//
//#pragma endregion

#pragma region �鲢����

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
/// �鲢����
/// </summary>
/// <param name="nums"></param>
void mergeSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;
  process(nums, 0, len - 1);
}

#pragma endregion

#pragma region ��������

/**
 * �����ݵ����λ��,�����������
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
/// ��������
/// </summary>
/// <param name="nums"></param>
void radixSort(std::vector<int> &nums) {
  int d = maxBit(nums), len = nums.size();
  std::vector<int> tmp(len);
  int radix = 1;
  for (int i = 1; i <= d; i++) { //����d������
	int t = 0;
	for (int j = 0; j < 10; j++) { //����λ��С������Ͱ��
	  for (int k = 0; k < len; k++) {
		if (nums[k] / radix % 10 == j) {
		  tmp[t++] = nums[k];
		}
	  }
	  if (t == len) break;
	}
	nums = tmp; //����ʱ��������ݸ��ƻ�ȥ
	radix *= 10;
  }
}

#pragma endregion

#pragma region ������

// ��start ��end�����ڣ�������ڵ�С���ӽڵ㣬�ͽ���
void heapify(std::vector<int> &nums, int start, int end) {
  int root = start;
  int child = 2 * root + 1; //���ӽڵ�
  while (child < end) {                                                  // ���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
	if (child + 1 <= end && nums[child] < nums[child + 1]) ++child;   //�ȱȽ������ӽڵ��С��ѡ������
	if (nums[child] <= nums[root]) return;                            //������ڵ�����ӽڵ���������ϣ�ֱ����������
	std::swap(nums[root], nums[child]);                                  //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
	root = child;
	child = 2 * root + 1;
  }
}

/// <summary>
/// ������
/// </summary>
/// <param name="nums"></param>
void heapSort(std::vector<int> &nums) {
  int len = nums.size();
  if (len < 2) return;

  // ��ʼ����i�����һ�����ڵ㿪ʼ����
  // �������ǰһ��Ϊ���ڵ㣬��һ��Ϊ�ӽڵ�
  for (int i = len / 2 - 1; i >= 0; --i) {
	heapify(nums, i, len - 1);
  }

  //�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
  for (int j = len - 1; j > 0; --j) {
	std::swap(nums[0], nums[j]);
	heapify(nums, 0, j - 1);
  }
}

#pragma endregion

#endif


