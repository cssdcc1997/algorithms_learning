#pragma once
#include <iostream>
#include <vector>

template<typename T>
void selection_sort_origin(T arr[], int n)
{
	for (int i = 0; i != n - 1; ++i)
	{
		int smallest_index = i;
		for (int j = i + 1; j != n; ++j)
		{
			if (arr[smallest_index] > arr[j])
			{
				smallest_index = j;
			}
		}

		std::swap(arr[i], arr[smallest_index]);
	}
}

template<typename T>
void bubble_sort_origin(T arr[], int n)
{
	for (int i = n - 1; i != 1; --i)
	{
		for (int j = 0; j != i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// �ɿӼ�¼��֮ǰϰ������j = i�� j ��= 0��arr[j] = arr[j - 1]�����ӡ����������һ�����������arr[0]��Զ���ᱻ�ı䣬
// ���Բ�����j = i - 1��arr[j + 1] = arr[j]
template<typename T>
void insertion_sort_origin(T arr[], int n)
{
	for (int i = 1; i != n; ++i)
	{
		int current_val = arr[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] > current_val)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				arr[j] = current_val;
				break;
			}
		}
	}
}

// ��������δ���
template<typename T>
void radix_sort_origin(T arr[], int n, int max, int range)
{
	std::vector<std::vector<int>> aux(range, std::vector<int>(1, 0));
	
	if (max%range)
	{

	}
	for (int i = 0; i != n; ++i)
	{
		aux[arr[i] % range].push_back(arr[i]);
	}

	for (int i = 0; i != range; ++i)
	{
		for (int j = 1; j != aux[i].size(); ++j)
		{
			arr[i] = aux[i][j];
		}
	}
}

template<typename T>
void __merge(T arr[], int left, int mid, int right)
{
	// VS��֧�ֶ�̬�������飬������ʹ��T aux[right - left + 1]�ķ�ʽ����aux�ؼ�
	// ��ʹ��VS����ʹ��new�ķ�ʽ����ؼ�
	// ʹ��new֮�󣬲�Ҫ������ʹ�ù���delete������Ŀռ�
	T* aux = new T[right - left + 1];

	for (int i = 0; i != right - left + 1; ++i)
	{
		aux[i] = arr[i + left];
	}

	int left_index = left;
	int right_index = mid + 1;

	for (int i = left; i != right + 1; ++i)
	{
		if (left_index > mid)
		{
			arr[i] = aux[right_index - left];
			++right_index;
		}
		else if (right_index > right)
		{
			arr[i] = aux[left_index - left];
			++left_index;
		}
		else if (aux[left_index - left] <= aux[right_index - left])
		{
			arr[i] = aux[left_index - left];
			++left_index;
		}
		else if (aux[left_index - left] > aux[right_index - left])
		{
			arr[i] = aux[right_index - left];
			++right_index;
		}
	}

	delete[] aux;
}

template<typename T>
void __merge_sort_recursion_origin(T arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;
	__merge_sort_recursion_origin(arr, left, mid);
	__merge_sort_recursion_origin(arr, mid + 1, right);
	__merge(arr, left, mid, right);
}

template<typename T>
void merge_sort_recursion_origin(T arr[], int n)
{
	__merge_sort_recursion_origin(arr, 0, n - 1);
}

template<typename T>
void merge_sort_iteration_origin(T arr[], int n)
{
	int size = 1;
	for (int i = 0; i < n; i += size)
	{
		for (int j = 0; j < n; j += size * 2)
		{
			__merge(arr, j, (j * 2 + size) / 2 , j + size);
		}
	}
}