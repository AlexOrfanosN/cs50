#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Allocate memory for plate number
        char *plate = malloc(strlen(buffer) + 1);
        if (plate == NULL)
        {
            printf("Error: unable to allocate memory\n");
            return 1;
        }

        // Copy plate number to newly allocated memory
        strcpy(plate, buffer);

        // Save pointer to newly allocated memory in array
        plates[idx] = plate;
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);

        // Free memory allocated for each plate number
        free(plates[i]);
    }
}