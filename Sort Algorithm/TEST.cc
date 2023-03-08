#define CATCH_CONFIG_MAIN

#include "../Catch/catch.hpp"
#include "sortAlgorithm.h"

TEST_CASE("Sort Algorithm", "[sortAlgorithm]")
{
  SECTION("bubble sort")
  {
	std::vector<int> arr{3, 2, 8, 6, 0, 9, 7};
	std::vector<int> ans{0, 2, 3, 6, 7, 8, 9};
	bubbleSort(arr);
	printArr(arr);
	REQUIRE(arr == ans);
  }

  SECTION("selection sort")
  {
	std::vector<int> arr{3, 2, 8, 6, 0, 9, 7};
	std::vector<int> ans{0, 2, 3, 6, 7, 8, 9};
	selectionSort(arr);
	//printArr(arr);
	REQUIRE(arr == ans);
  }

  SECTION("insert sort")
  {
	std::vector<int> arr{3, 2, 8, 6, 0, 9, 7};
	std::vector<int> ans{0, 2, 3, 6, 7, 8, 9};
	insertSort(arr);
	//printArr(arr);
	REQUIRE(arr == ans);
  }

  SECTION("shell sort")
  {
	std::vector<int> arr{3, 2, 8, 6, 0, 9, 7};
	std::vector<int> ans{0, 2, 3, 6, 7, 8, 9};
	shellSort(arr);
	//printArr(arr);
	REQUIRE(arr == ans);
  }

  SECTION("quick sort")
  {
	std::vector<int> arr{12, 1, 3, 21, 5, 16, 8, 3, 15, 26, 1, 17, 31};
	std::vector<int> ans{1, 1, 3, 3, 5, 8, 12, 15, 16, 17, 21, 26, 31};
	quickSort(arr);
	//printArr(arr);
	REQUIRE(arr == ans);
  }

  SECTION("merge sort")
  {
	std::vector<int> arr{3, 2, 8, 6, 0, 9, 7};
	std::vector<int> ans{0, 2, 3, 6, 7, 8, 9};
	mergeSort(arr);
	//printArr(arr);
	REQUIRE(arr == ans);
  }

  SECTION("heap sort")
  {
	std::vector<int> arr{3, 2, 8, 6, 0, 9, 7};
	std::vector<int> ans{0, 2, 3, 6, 7, 8, 9};
	heapSort(arr);
	//printArr(arr);
	REQUIRE(arr == ans);
  }
}