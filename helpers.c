#include "helpers.h"
#include "math.h"
#include "stdlib.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float bgrAve = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            int bgrAveInt = round(bgrAve);
            image[i][j].rgbtBlue = bgrAveInt;
            image[i][j].rgbtGreen = bgrAveInt;
            image[i][j].rgbtRed = bgrAveInt;
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
            float sepBlue = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            float sepGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;

            float sepRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;

            if (round(sepBlue) > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepBlue);
            }

            if (round(sepGreen) > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepGreen);
            }
            if (round(sepRed) > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepRed);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tempPix = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tempPix;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagecopy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagecopy[i][j] = image[i][j];
        }
    }

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            float sumBlue = 0;
            float sumGreen = 0;
            float sumRed = 0;
            int counter = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((i + k) < 0 || (i + k) >= height)
                    {
                        continue;
                    }
                    if ((j + l) < 0 || (j + l) >= width)
                    {
                        continue;
                    }
                    else
                    {
                        sumBlue += imagecopy[i + k][j + l].rgbtBlue;
                        sumGreen += imagecopy[i + k][j + l].rgbtGreen;
                        sumRed += imagecopy[i + k][j + l].rgbtRed;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtBlue = round(sumBlue / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtRed = round(sumRed / counter);
        }
    }

    return;
}
