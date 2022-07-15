#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // adds together all 3 values and averages them
            // not sure why it has to be 3.0 vs 3
            int temp = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            if (temp > 255)
            {
                // if over max value 255 set to max
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
            // cal change to var and round to nearest int
            int SB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int SG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int SR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            // if value ends up above max, set to max
            if (SB > 255)
            {
                SB = 255;
            }
            if (SG > 255)
            {
                SG = 255;
            }
            if (SR > 255)
            {
                SR = 255;
            }
            image[i][j].rgbtBlue = SB;
            image[i][j].rgbtGreen = SG;
            image[i][j].rgbtRed = SR;
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
    RGBTRIPLE imgcpy[height][width];
    int blur = 1;
    // copy input into duplicate array
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            imgcpy[i][j] = image[i][j];
        }
    }
    // take pixel and compare it to +1, =, -1 height and +1, =, -1 width and average it
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int SB = 0, SG = 0, SR = 0;
            float smpsize = 0;
            for(int k = (0 - blur); k < (0 + blur) + 1; k++)
            {
                for(int l = (0 - blur); l < (0 + blur) + 1; l++)
                {
                    if(i + k < 0 || i + k > height || j + l < 0 || j + l > width)
                    {
                        break;
                    }
                    SB = SB + imgcpy[i + k][j + l].rgbtBlue;
                    SG = SG + imgcpy[i + k][j + l].rgbtGreen;
                    SR = SR + imgcpy[i + k][j + l].rgbtRed;
                    smpsize++;
                }
            }
            image[i][j].rgbtBlue = round(SB/smpsize);
            image[i][j].rgbtGreen = round(SG/smpsize);
            image[i][j].rgbtRed = round(SR/smpsize);
        }
    }
    return;
}
