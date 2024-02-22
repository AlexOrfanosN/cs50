#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // find the length of the string
    int length = strlen(input);
    // create a base case
    if (length == 1)
    {
        return input[0] - 48;
    }

    // int j = last digit char mode
    char j = input[length - 1];
    // int k = last digit converted to int
    int k = j - 48;

    //move char one step to the left of the string
    input[length - 1] = '\0';

    //Return this value plus 10 times the integer value of the new shortened string.

    return k + 10 * convert(input);



}