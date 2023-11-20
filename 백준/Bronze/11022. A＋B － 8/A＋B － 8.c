#include <stdio.h>
int main() {
	int t, i, a, b;
	scanf("%d", &t);

	for (i = t; i > 0; i--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", t - i + 1, a, b, a + b);
	}
	return 0;
}