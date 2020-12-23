#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtRed =  average;
            image[i][j].rgbtBlue =  average;
            image[i][j].rgbtGreen =  average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
           int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
           int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
           int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
           image[i][j].rgbtRed = fmin(255,sepiaRed);
           image[i][j].rgbtGreen = fmin(255,sepiaGreen);
           image[i][j].rgbtBlue = fmin(255,sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2 ; j++)
        {
           temp = image[i][j];
           image [i][j] = image[i][width - (j+1)];
           image[i][width-(j+1)] = temp;

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            temp[i][j]= image[i][j];
        }
    }
    for (int i=0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            float red  =0;
            float blue =0;
            float green=0;
            float count=0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && j+l >=0 && i+k < height && j+l < width)
                    {
                        red += temp[i+k][j+l].rgbtRed;
                        blue += temp[i+k][j+l].rgbtBlue;
                        green += temp[i+k][j+l].rgbtGreen;
                        count++;
                    }
                }
            }
            image[i][j].rgbtRed = round (red/count);
            image[i][j].rgbtBlue = round (blue/count);
            image[i][j].rgbtGreen = round (green/count);
        }
    }
    return;
}
