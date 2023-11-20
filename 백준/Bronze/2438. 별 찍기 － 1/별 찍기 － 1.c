#include <stdio.h>
int main() {
	int i, j, k;
	scanf("%d", &i);

	for (j = i; j > 0; j--)
	{
		for (k = i - j + 1; k > 0; k--) {
			printf("*");
		}
		printf("\n");
	}
}