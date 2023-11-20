#include <stdio.h>

int main()
{
    int i, j, k, l = 0;
    scanf("%d", &i);
    for (j = 1; j < 2 * i; j++)
    {
        for (k = 1; k <= 2 * i; k++)
        {
            if (j <= i)
            {
                if (k < j + 1)
                    printf("*");
                else if (k > 2 * i - j)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                if (k >= j + 1)
                    printf("*");
                else if (k <= 2 * i - j)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}