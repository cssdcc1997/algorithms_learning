#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>

namespace sort_test_handler
{
	// ����n��Ԫ�ص�������飬 ÿ��Ԫ�ص������ΧΪ[]
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

	// ����һ���������������
	// ��������һ������[0...n - 1]����ȫ�������飬֮���漴����swap_times������
	// swap_times���û����壬�������������̶�
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

	// ������������a�е�����Ԫ�ص�һ���µ����飬�������µ�����
	template<typename T>
	T* copy_array(T arr[], int n)
	{
		T* ret = new int[n];
		//* ��VSzhong ,copy��������Ϊ�ǲ���ȫ�ģ��Լ��ֶ�дһ��forѭ��
		//copy(a, a + n, arr);
		for (int i = 0; i != n; ++i)
		{
			ret[i] = arr[i];
		}

		return ret;
	}

	// ��ӡarr�������������
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

	// �ж�arr�����Ƿ�����
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

	// ����sort�����㷨������ʱ�����ȷ�ԣ���λΪ����ms
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