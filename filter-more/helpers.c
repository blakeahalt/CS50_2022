#include "helpers.h"
#include <math.h>

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
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        int reverse = 0;
        for (int j = width - 1; j >= 0; j--, reverse++)
        {
            temp[i][reverse] = image[i][j];
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
                        // totalR = index.rgbtRed++;
                        // totalG = index.rgbtGreen++;
                        // totalB = index.rgbtBlue++;
                        totalR += (index.rgbtRed);
                        totalG += (index.rgbtGreen);
                        totalB += (index.rgbtBlue);
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

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int RowCoor[] = {i - 1, i, i + 1};
            int ColCoor[] = {j - 1, j, j + 1};

            int GxMatrix[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int GyMatrix[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
            float GxRed = 0;
            float GxGreen = 0;
            float GxBlue = 0;
            float GyRed = 0;
            float GyGreen = 0;
            float GyBlue = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int currRow = RowCoor[r];
                    int currCol = ColCoor[c];
                    if (currRow >= 0 && currRow < height && currCol >= 0 && currCol < width)
                    {
                        RGBTRIPLE index = image[currRow][currCol];

                        GxRed += GxMatrix[r][c] * index.rgbtRed;
                        GxGreen += GxMatrix[r][c] * index.rgbtGreen;
                        GxBlue += GxMatrix[r][c] * index.rgbtBlue;

                        GyRed += GyMatrix[r][c] * index.rgbtRed;
                        GyGreen += GyMatrix[r][c] * index.rgbtGreen;
                        GyBlue += GyMatrix[r][c] * index.rgbtBlue;
                    }
                }
            }
            int totRed = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int totGreen = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int totBlue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            temp[i][j].rgbtRed = totRed > 255 ? 255 : totRed;
            temp[i][j].rgbtGreen = totGreen > 255 ? 255 : totGreen;
            temp[i][j].rgbtBlue = totBlue > 255 ? 255 : totBlue;
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