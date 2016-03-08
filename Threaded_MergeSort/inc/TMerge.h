

#ifndef __MY_Header__
#define __MY_Header__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct arr_info {
	int low;
	int high;
	int *data;
} arr_info_t, *arr_info_p;

void merge(int *, int, int);
void *merge_sort(void *);

#endif
