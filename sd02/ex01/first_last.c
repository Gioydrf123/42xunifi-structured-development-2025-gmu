void first_last(int arr[], int size, int target, int *first, int *last)
{
	*first = -1;
	*last = -1;

	for(int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			*last = i;
		if (*first == -1)
			*first = i;
		}
	}
}
