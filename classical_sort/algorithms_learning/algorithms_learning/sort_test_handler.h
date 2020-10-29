#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>

namespace sort_test_handler
{
	// 生成n个元素的随机数组， 每个元素的随机范围为[]
	int* generate_random_array(int n, int range_l, int range_r)
	{
		int* arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i != n; ++i)
		{
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
		}

		return arr;
	}

	// 生成一个近乎有序的数组
	// 首先生成一个含有[0...n - 1]的完全有序数组，之后随即交换swap_times对数据
	// swap_times由用户定义，代表数组的无序程度
	int* generate_nearly_ordered_array(int n, int swap_times)
	{
		int* arr = new int[n];
		for (int i = 0; i != n; ++i)
		{
			arr[i] = i;
		}

		srand(time(NULL));
		for (int i = 0; i != swap_times; ++i)
		{
			int pos_x = rand() % n;
			int pos_y = rand() % n;
			std::swap(arr[pos_x], arr[pos_y]);
		}

		return arr;
	}

	// 拷贝整型数组a中的所有元素到一个新的数组，并返回新的数组
	template<typename T>
	T* copy_array(T arr[], int n)
	{
		T* ret = new int[n];
		//* 在VSzhong ,copy函数被认为是不安全的，自己手动写一遍for循环
		//copy(a, a + n, arr);
		for (int i = 0; i != n; ++i)
		{
			ret[i] = arr[i];
		}

		return ret;
	}

	// 打印arr数组的所有内容
	template<typename T>
	void print_array(T arr[], int n)
	{
		for (int i = 0; i != n; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		return;
	}

	// 判断arr数组是否有序
	template<typename T>
	bool is_sorted(T arr[], int n)
	{
		for (int i = 0; i != n - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}

		return true;
	}

	// 测试sort排序算法的运行时间和正确性，单位为毫秒ms
	template<typename T>
	void test_sort_algorithm(const std::string &sort_name, void(*sort)(T [], int), T arr[], int n)
	{
		clock_t start_time = clock();
		sort(arr, n);
		clock_t end_time = clock();
		std::cout << sort_name << " : " << double(end_time - start_time) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;

		return;
	}
}