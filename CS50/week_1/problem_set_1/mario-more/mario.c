#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get height from user
    int input;
    do
    {
        input = get_int("Height:");
    }
    while (input <= 0 || input > 8);

    // i = height of pyramid
    int height = input;
    // first row of spaces
    int space1;
    // first row of hashes
    int hash1;
    //second row of spaces
    int space2;
    // second row of hashes
    int hash2;


    for (height = input; height > 0; height--)
    {
        for (space1 = 1; space1 < height; space1++)
        {
            printf(" ");
        }
        for (hash1 = (space1 - 1); hash1 < input; hash1++)
        {
            printf("#");
        }
        for (space2 = 2; space2 > 0; space2--)
        {
            printf(" ");
        }
        for (hash2 = (space1 - 1); hash2 < input; hash2++)
        {
            printf("#");
        }
        printf("\n");
    }


}