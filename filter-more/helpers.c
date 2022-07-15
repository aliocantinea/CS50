#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
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

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0, k = width - 1; j < width / 2; ++j, --k)
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
    //create a function var for a copy of the image
    //will release memory back when function ends
    RGBTRIPLE imgcpy[height][width];
    //variable for blur, so it could be incorporated later to be dynamic
    int blur = 1;
    // copy input into duplicate array
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            imgcpy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            //set RGB struct to 0 each time you move to a pixel
            int SB = 0, SG = 0, SR = 0;
            //float so that it doesn't create a float dump
            //samplesize var that adds up each time a pixel is used in average
            float smpsize = 0;
            //take pixel from above and compare it to +1, =, -1 height and +1, =, -1 width
            //'1' here is equal to blur value of var at start of function
            for (int k = (0 - blur); k < (0 + blur) + 1; ++k)
            {
                for (int l = (0 - blur); l < (0 + blur) + 1; ++l)
                {
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width)
                    {
                        //if outside of picture ignores pixel comparison by contining loop
                        continue;
                    }
                    //samples impcpy so that as variables change on image it doesn't change blur
                    //SB += x; is the same as SB = SB + x;
                    SB += imgcpy[i + k][j + l].rgbtBlue;
                    SG += imgcpy[i + k][j + l].rgbtGreen;
                    SR += imgcpy[i + k][j + l].rgbtRed;
                    ++smpsize;
                }
            }
            //copy average from temp var to image
            image[i][j].rgbtBlue = round(SB / smpsize);
            image[i][j].rgbtGreen = round(SG / smpsize);
            image[i][j].rgbtRed = round(SR / smpsize);
            //loops back to next pixel
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
