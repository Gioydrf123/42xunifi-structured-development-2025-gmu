float	average(const int *arr, int size)
{
	int sum = 0;
	int count = 0;

	for(;size > 0; ++arr, --size, ++count)
	{
		if(*arr >= 0 && *arr <= 100)
			sum += *arr;
	}
	if (count == 0)
		return 0;
	return (float)sum / count;
}
/*
#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%f\n", average(arr, 5));
}*/
