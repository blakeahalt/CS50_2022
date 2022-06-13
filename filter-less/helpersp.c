#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height - 1; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            float avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }
        return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float SepiaRed;
    float SepiaGreen;
    float SepiaBlue;

       int **RnewRed = malloc(sizeof(int*) * width);
       int **RnewGreen = malloc(sizeof(int*) * width);
       int **RnewBlue = malloc(sizeof(int*) * width);

    for (int i = 0; i < height - 1; i++)
    {

        for (int j = 0; j < width - 1; j++)
        {
            // if (round(image[i][j].rgbtRed * .393) > 255 || round(image[i][j].rgbtGreen * .769) > 255 || round(image[i][j].rgbtBlue * .189) > 255)
            // {
            float origRed = image[i][j].rgbtRed;
            float origGreen = image[i][j].rgbtGreen;
            float origBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(origRed * .393 + origGreen * .769 + origBlue * .189);
            int sepiaGreen = round(origRed * .349 + origGreen * 686 + origBlue * .168);
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
check50 cs50/problems/2022/x/filter/less


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
