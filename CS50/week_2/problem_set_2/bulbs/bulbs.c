#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;


void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: \n");
    for (int i = 0; i < strlen(message); i++)
    {
        int BINARY[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int digit = message[i];
        int j = 0;

        while (digit > 0)
        {
            BINARY[j] = digit % 2;
            digit = digit / 2;
            j++;
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(BINARY[k]);
        }
        printf("\n");
    }

}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
