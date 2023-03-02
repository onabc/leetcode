#ifndef PRINTARR_H
#define PRINTARR_H

/// <summary>
/// ��ӡ����
/// </summary>
/// <param name="arr"></param>
void printArr(std::vector<int> &arr) {
  int len = arr.size();
  std::cout << "[";
  if (len > 1) {
	for (int i = 0; i < len; ++i) {
	  std::cout << arr[i] << (i < len - 1 ? ", " : " ");
	}
  }
  std::cout << "]" << std::endl;
}

#endif // !PRINTARR_H
