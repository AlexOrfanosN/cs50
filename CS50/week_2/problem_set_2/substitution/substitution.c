#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //get correct key from user
    //validate that input contains only one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string lock = argv[1];
    //validate that input argument is 26 letters long
    if (strlen(lock) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //validate that input argument has only letters
    for (int i = 0; i < strlen(lock); i++)
    {
        if (!isalpha(lock[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    //validate that input argument has only unique letters
    for (int i = 0; i < strlen(lock); i++)
    {
        for (int j = i + 1; j < strlen(lock); j++)
        {
            if (toupper(lock[i]) == toupper(lock[j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    // get plaintext from user
    string plaintext = get_string("plaintext: ");
    // make uppercase letters
    for (int i = 0; i < strlen(lock); i++)
    {
        if (islower(lock[i]))
        {
            lock[i] -= 32;
        }
    }
    //start printing the ciphertext
    printf("ciphertext: ");
    // convert plaintext to ciphertext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", lock[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", lock[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}