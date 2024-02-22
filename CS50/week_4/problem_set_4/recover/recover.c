#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // open file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s./n", argv[1]);
        return 2;
    }

    // create array of 512 bytes to store blocks
    unsigned char buffer[512];

    // set counter for images created
    int counter = 0;

    // set pointer for images
    FILE *outptr = NULL;

    // malloc
    char *filename = malloc(8 * sizeof(char));

    // Read memory
    while (fread(buffer, sizeof(char), 512, inptr))
    {
        // check for JPEG headers
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter > 0)
            {
                fclose(outptr);
            }

            // JPEG Filenames
            sprintf(filename, "%03i.jpg", counter);

            // open file to write new image
            outptr = fopen(filename, "w");

            // keep track of images found
            counter++;
        }
        // check if outptr is valid
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outptr);
        }
    }
    free(filename);
    fclose(outptr);
    fclose(inptr);

    return 0;
}