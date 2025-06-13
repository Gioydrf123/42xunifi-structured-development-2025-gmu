#include <stdbool.h>
#include <stdio.h>

int count_critical_windows(const int *readings, int size)
{
	int tmp = 0;
	bool is_critic = false;
	int num_critic = 0;
	int gr8_70 = 0;
	for (int i = 0; i < size; ++i)
	{
		for(;tmp < 5 && i < size; ++tmp, ++i)
		{
			if(readings[i]>150 || gr8_70>=3)
				is_critic = true;
			if(readings[i]>= 70)
				++gr8_70;

		}
		if(tmp == 5)
		{
			if(((readings[i-1]+readings[i-2]+readings[i-3]+readings[i-4]+readings[i-5])/5) >= 90)
				is_critic = true;
		}
		tmp = 0;
		gr8_70 = 0;
		if (is_critic)
		{
			++num_critic;
			is_critic = false;
		}
	}
	return num_critic;
}

//#include <stdio.h>
//
//int main()
//{
//    int readings[] = {170, 1, 05, 40, 60, 170, 1, 05, 40, 60, 170, 1, 05, 40, 60, 170, 1, 05, 40, 60};
//    int size = sizeof(readings) / sizeof(readings[0]);
//
//    printf("Finestre critiche: %d\n", count_critical_windows(readings, size));
//    return 0;
//}
