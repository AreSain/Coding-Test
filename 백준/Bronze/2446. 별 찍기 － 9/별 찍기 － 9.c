#include <stdio.h>

int main()
{
    int i, j, k;
    scanf("%d", &i);
    for (j = 1; j < 2 * i; j++)
    {
        for (k = 1; k <= 2 * i; k++)
        {
            if (j <= i)
            {
                if (k >= 2 * j)
                    printf("*");
                else if (k < j)
                    printf(" ");
            }
            else
            {
                if (k >= 4 * i - 2 * j)
                    printf("*");
                else if (k < 2 * i - j)
                    printf(" ");
            }
        }
        printf("\n");
    }
}