#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < width; row++)
    {
        for (int column = 0; column < height; column++)
        {
            int avgClr = round((image[column][row].rgbtBlue + image[column][row].rgbtGreen + image[column][row].rgbtRed) / 3.0);

            image[column][row].rgbtBlue = avgClr;
            image[column][row].rgbtGreen = avgClr;
            image[column][row].rgbtRed = avgClr;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < width; row++)
    {
        for (int column = 0; column < height; column++)
        {
            int sepiaRed =
                round(.393 * image[column][row].rgbtRed + .769 * image[column][row].rgbtGreen + .189 * image[column][row].rgbtBlue);
            int sepiaGreen =
                round(.349 * image[column][row].rgbtRed + .686 * image[column][row].rgbtGreen + .168 * image[column][row].rgbtBlue);
            int sepiaBlue =
                round(.272 * image[column][row].rgbtRed + .534 * image[column][row].rgbtGreen + .131 * image[column][row].rgbtBlue);

            if (sepiaBlue > 255)
            {
                image[column][row].rgbtBlue = 255;
            }
            else
                image[column][row].rgbtBlue = sepiaBlue;

            if (sepiaGreen > 255)
            {
                image[column][row].rgbtGreen = 255;
            }
            else
                image[column][row].rgbtGreen = sepiaGreen;

            if (sepiaRed > 255)
            {
                image[column][row].rgbtRed = 255;
            }
            else
                image[column][row].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width / 2; row++)
        {
            RGBTRIPLE tmp = image[column][row];
            image[column][row] = image[column][width - (row + 1)];
            image[column][width - (row + 1)] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int allRed = 0;
            int allBlue = 0;
            int allGreen = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int possX = i + x;
                    int possY = j + y;

                    if (possX < 0 || possX > (height - 1) || possY < 0 || possY > (width - 1))
                    {
                        continue;
                    }
                    allRed += image[possX][possY].rgbtRed;
                    allBlue += image[possX][possY].rgbtBlue;
                    allGreen += image[possX][possY].rgbtGreen;

                    counter++;
                }
            }

            tmp[i][j].rgbtRed = round(allRed / counter);
            tmp[i][j].rgbtBlue = round(allBlue / counter);
            tmp[i][j].rgbtGreen = round(allGreen / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }

    return;
}
