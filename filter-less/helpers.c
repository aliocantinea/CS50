#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int temp = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed / 3.0;
            if (temp > 255)
            {
                temp = 255;
            }
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int temp = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed / 3.0;
            if (temp > 255)
            {
                temp = 255;
            }
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0, k = width - 1; j < width / 2; j++, k--)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
