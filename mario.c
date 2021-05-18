#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < (n - i - 1) ; q++)
        {
            printf(" ");

        }
        for (int l = 0; l < (i + 1); l++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
