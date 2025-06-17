int count_segments(const int *arr, int size)
{
	int segment = 0;

	--size;
	while (size >= 0)
	{
		if(arr[size] != -1 && size+1 >= 0)
		{
			size--;
			if(arr[size+1] >= arr[size] && size+1 >= 0)
			{
				size--;
				if(arr[size+1] >= arr[size] && size+1 >= 0)
				{
					size--;
					++segment;
					while(arr[size] != -1)
					{
						if (size >= 0 && arr[size]!=-1 && arr[size+1] <= arr[size])
						{
							size--;
							--segment;
							break ;
						}
						--size;
					}
				}
			}
		}
	}
	return segment;
}

//#include <stdio.h>
//
//int main()
//{
//	int arr[13]={1,2,0,-1 ,-3 ,4, 1, 2, 3, -1, 4, 5, 6};
//	int size =13;
//
//	printf("%d\n", count_segments(arr, size));
//}
