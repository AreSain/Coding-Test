#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, temp, see = 1, i = 0, j = 0, top = 0;
	int* arr;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	if (!arr)
		return 0;
	while (n > 0)
	{
		scanf("%d", &temp);
		arr[i] = temp;
		i++;
		n--;
	}
	top = arr[i - 1];
	while (j < i)
	{
		if (arr[i - 1 - j] > top)
		{
			see++;
			top = arr[i - 1 - j];
		}
		j++;
	}
	free(arr);
	printf("%d", see);
}