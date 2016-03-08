#include "TMerge.h"

int main()
{
	arr_info_t arr_info;
	pthread_t thread;
	int loop;
	int num;

	printf("\nEnter Total Number of Elements to be Sort: ");
	scanf("%d",&num);

	arr_info.data = (int *)malloc(num * sizeof(int));

	if ( arr_info.data == NULL ) {
		printf("Memory initialization failed\n");
		exit(1);
	}

	printf("\nEnter Array Elements which to be Sort: ");
	for ( loop = 0; loop < num; loop++ ) 
		scanf("%d", &arr_info.data[loop]);

	arr_info.low = 0;
	arr_info.high = num - 1;

	pthread_create(&thread, NULL, merge_sort, &arr_info);
	pthread_join(thread, NULL);

	for ( loop = 0; loop < num; loop++ ) 
		printf ("%d ", arr_info.data[loop]);
	printf("\n");

	return 0;
}
