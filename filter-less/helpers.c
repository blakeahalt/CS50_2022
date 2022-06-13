#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float origRed = image[i][j].rgbtRed;
            float origGreen = image[i][j].rgbtGreen;
            float origBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(origRed * .393 + origGreen * .769 + origBlue * .189);
            int sepiaGreen = round(origRed * .349 + origGreen * .686 + origBlue * .168);
            int sepiaBlue = round(origRed * .272 + origGreen * .534 + origBlue * .131);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        int tempZeroIndex = 0;
        for (int j = width - 1; j >= 0; j--, tempZeroIndex++)
        {
            temp[i][tempZeroIndex] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int RowCoor[] = {i - 1, i, i + 1};
            int ColCoor[] = {j - 1, j, j + 1};
            float totalR = 0;
            float totalG = 0;
            float totalB = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int currRow = RowCoor[r];
                    int currCol = ColCoor[c];
                    // RGBTRIPLE index = image[currRow][currCol];
                    if (currRow >= 0 && currRow < height && currCol >= 0 && currCol < width)
                    {
                        RGBTRIPLE index = image[currRow][currCol];
                        totalR = index.rgbtRed++;
                        totalG = index.rgbtGreen++;
                        totalB = index.rgbtBlue++;
                        // totalR += (index.rgbtRed);
                        // totalG += (index.rgbtGreen);
                        // totalB += (index.rgbtBlue);
                        count++;
                    }
                }
            }
            temp[i][j].rgbtRed = round(totalR / count);
            temp[i][j].rgbtGreen = round(totalG / count);
            temp[i][j].rgbtBlue = round(totalB / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}