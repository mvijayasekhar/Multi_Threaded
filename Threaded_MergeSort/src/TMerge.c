#include "TMerge.h"

void merge(int *arr_data, int low, int high)
{
	int mid = ( low + high ) / 2;
	int left = low;
	int right = mid + 1;

	int temp_arr[high - low + 1];
	int loop, cur = 0;

	while ( left <= mid && right <= high ) {
		if ( arr_data[left] <= arr_data[right] )
			temp_arr[cur++] = arr_data[left++];
		else
			temp_arr[cur++] = arr_data[right++];
	}

	while ( left <= mid )
		temp_arr[cur++] = arr_data[left++];

	while ( right <= high )
		temp_arr[cur++] = arr_data[right++];

	for ( loop = 0; loop <= (high - low) ; loop++ )
		arr_data[low + loop] = temp_arr[loop];
}
