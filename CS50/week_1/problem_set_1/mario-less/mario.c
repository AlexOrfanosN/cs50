#include <cs50.h>
#include <stdio.h>

int main(void)

// integer n = Height assigned by user
// integer i = Height of Triangle
// integer j = Number of spaces
// integer k = Number of Hashes
{
// Get height from user
    int n;
    do
    {
        n = get_int("Height: ");
    }

    while (n > 8 || n < 1);
// Make triangle
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}