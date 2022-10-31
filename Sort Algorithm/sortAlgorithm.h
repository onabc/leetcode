/// <summary>
/// ð������
/// </summary>
/// <param name="arr"></param>
void bubbleSort(std::vector<int>& arr)
{
	int len = arr.size();
	if (len <= 1) return;
	for (int i = 0; i < len - 1; ++i)
	{
		bool isSwap = false;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				isSwap = true;
			}
		}

		if (!isSwap) break;
	}
}

/// <summary>
/// ѡ������
/// </summary>
/// <param name="nums"></param>
void selectionSort(std::vector<int>& nums)
{
	int len = nums.size();
	if (len <= 1) return;
	for (int i = 0; i < len - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (nums.at(minIndex) > nums[j]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(nums.at(minIndex), nums.at(i));
		}
	}
}

/// <summary>
/// ��������
/// </summary>
/// <param name="nums"></param>
void insertSort(std::vector<int>& nums) {
	int len = nums.size();
	if (len <= 1) return;
	for (int i = 1; i < len; ++i) {
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

/// <summary>
/// ϣ������-�ƶ���
/// </summary>
/// <param name="nums"></param>
void shellSort(std::vector<int>& nums) {
	int len = nums.size();
	if (len <= 1) return;
	for (int gap = len / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < len; ++i) {
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

void quickSortSub(std::vector<int>& nums, int left, int right) {
	if (left > right) return;
	int base = nums[left];
	int i = left, j = right;
	while (i != j) {
		while (nums[j] >= base && i < j) --j;
		while (nums[i] <= base && i < j) ++i;
		if (i < j) {
			std::swap(nums[i], nums[j]);
		}
	}
	// ����׼���ŵ��м��λ�ã���׼����λ��
	nums[left] = nums[i];
	nums[i] = base;

	quickSortSub(nums, left, i - 1);
	quickSortSub(nums, i + 1, right);
}
/// <summary>
/// ��������
/// </summary>
/// <param name="nums"></param>
void quickSort(std::vector<int>& nums) {
	int len = nums.size();
	if (len < 2) return;
	quickSortSub(nums, 0, len - 1);
}

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
void mergeSort(std::vector<int>& nums, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}
/// <summary>
/// �鲢����
/// </summary>
/// <param name="nums"></param>
void mergeSort(std::vector<int>& nums) {
	int len = nums.size();
	if (len < 2) return;
	mergeSort(nums, 0, len - 1);
}

/// <summary>
/// ��������
/// </summary>
/// <param name="nums"></param>
void radixSort(std::vector<int>& nums)
{
}

/// <summary>
/// ��ӡ����
/// </summary>
/// <param name="arr"></param>
void printArr(std::vector<int>& arr)
{
	int len = arr.size();
	std::cout << "[";
	if (len > 1) {
		for (int i = 0; i < len; ++i) {
			std::cout << arr[i] << (i < len - 1 ? ", " : " ");
		}
	}
	std::cout << "]" << std::endl;
}