#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //get correct key from user
    if (argc != 2 || argv[1] < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string lock = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // get the plaintext from user
    string plaintext = get_string("plaintext: ");
    // convert the key to integer
    int key = atoi(lock);
    // print the ciphertext
    printf("ciphertext: ");
    //transpose the plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + key) % 26) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + key) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}