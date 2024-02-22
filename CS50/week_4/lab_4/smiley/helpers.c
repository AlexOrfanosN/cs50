#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int row = 0; row < width; row++)
    {
        for (int column = 0; column < height; column++)
        {
            if (image[row][column].rgbtBlue == 0 && image[row][column].rgbtRed == 0 && image[row][column].rgbtGreen == 0)
            {
                image[row][column].rgbtBlue = 255;
                image[row][column].rgbtRed = 255;
                image[row][column].rgbtGreen = 0;
            }

        }
    }
}
