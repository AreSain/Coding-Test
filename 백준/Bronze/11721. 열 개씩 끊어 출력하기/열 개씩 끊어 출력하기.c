#include <stdio.h>

int main()
{
	int j = 0;
	char arr[101];
	scanf("%s", arr);
	while (arr[j] != '\0')
	{
		printf("%c", arr[j]);
		if (j % 10 == 9)
		{
			printf("\n");
		}
		j++;
	}
	return 0;
}