#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, min, max;
	int j = 0;
	int* arr;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	while (n > 0)
	{
		scanf("%d", &arr[j]);
		j++;
		n--;
	}
	min = arr[0];
	max = arr[0];
	while (n < j)
	{
		if (arr[n] < min)
			min = arr[n];
		if (arr[n] > max)
			max = arr[n];
		n++;
	}
	printf("%d ", min);
	printf("%d", max);
	return 0;
}