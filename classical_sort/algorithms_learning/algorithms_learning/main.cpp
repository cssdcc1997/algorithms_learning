//
// Created by cssdcc1997 on 2020/10/29
//

#include "sort_test_handler.h"
#include "classical_sort.h"
#include <cmath>

int main()
{
	int size = pow(10, 5);
	//int* arr = sort_test_handler::generate_random_array(size, 0, size);
	int* arr = sort_test_handler::generate_nearly_ordered_array(size, size / 100);
	int* arr_2 = sort_test_handler::copy_array(arr, size);
	int* arr_3 = sort_test_handler::copy_array(arr, size);
	int* arr_4 = sort_test_handler::copy_array(arr, size);

	//sort_test_handler::test_sort_algorithm("selection_sort_origin", selection_sort_origin, arr, size);
	//sort_test_handler::test_sort_algorithm("bubble_sort_origin", bubble_sort_origin, arr_2, size);
	sort_test_handler::test_sort_algorithm("insertion_sort_origin", insertion_sort_origin, arr_3, size);
	sort_test_handler::test_sort_algorithm("merge_sort_origin", merge_sort_recursion_origin, arr_4, size);
	
	delete[] arr;
	delete[] arr_2;
	delete[] arr_3;

	system("pause");
	return 0;
}