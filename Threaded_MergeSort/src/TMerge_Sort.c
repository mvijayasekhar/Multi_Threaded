#include "TMerge.h"

void * merge_sort(void *a_info)
{
	arr_info_t left_sub_arr;
	arr_info_t right_sub_arr;

	pthread_t left_sub_thread;
	pthread_t right_sub_thread;

	arr_info_p arr_info = (arr_info_p)a_info;
	int mid = ( arr_info->low + arr_info->high ) / 2;

	left_sub_arr.low = arr_info->low;
	left_sub_arr.high = mid;
	left_sub_arr.data = arr_info->data;

	right_sub_arr.low = mid + 1;
	right_sub_arr.high = arr_info->high;
	right_sub_arr.data = arr_info->data;

	if ( arr_info->low >= arr_info->high ) 
		return NULL;

	pthread_create(&left_sub_thread, NULL, merge_sort, &left_sub_arr);
	pthread_create(&right_sub_thread, NULL, merge_sort, &right_sub_arr);
	
	pthread_join(left_sub_thread, NULL);
	pthread_join(right_sub_thread, NULL);

	merge(arr_info->data, arr_info->low, arr_info->high);

	pthread_exit(NULL);
}
