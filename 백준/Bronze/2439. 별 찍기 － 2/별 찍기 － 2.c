#include <stdio.h>
int main() {
	int i, j, k;
	scanf("%d", &i);

	for (j = i; j > 0; j--)
	{
		for (k = 1; k < i + 1; k++) {
			if ( k/j >= 1 ) { printf("*"); }
			else { printf(" "); }
		}
		printf("\n");
	}
}