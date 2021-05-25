#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blue;
    int green;
    int red;
    int counter;

    RGBTRIPLE cimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cimage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue = 0;
            green = 0;
            red = 0;
            counter = 1;

            if (j - 1 >= 0)
            {
                blue = cimage[i][j-1].rgbtBlue;
                green = cimage[i][j - 1].rgbtGreen;
                red = cimage[i][j-1].rgbtRed;
                counter++;

                if (i - 1 >= 0)
                {
                    blue = blue + cimage[i - 1][j-1].rgbtBlue;
                    green = green + cimage[i - 1][j - 1].rgbtGreen;
                    red = red + cimage[i - 1][j-1].rgbtRed;
                    counter++;
                }

                if (i + 1 < height)
                {
                    blue = blue + cimage[i + 1][j - 1].rgbtBlue;
                    green = green + cimage[i + 1][j - 1].rgbtGreen;
                    red = red + cimage[i + 1][j - 1].rgbtRed;
                    counter++;
                }
            }

            if (j + 1 < width)
            {
                blue =  blue + cimage[i][j + 1].rgbtBlue;
                green = green + cimage[i][j + 1].rgbtGreen;
                red = red + cimage[i][j + 1].rgbtRed;
                counter++;

                if (i - 1 >= 0)
                {
                    blue = blue + cimage[i - 1][j+1].rgbtBlue;
                    green = green + cimage[i - 1][j+1].rgbtGreen;
                    red = red + cimage[i - 1][j+1].rgbtRed;
                    counter++;
                }

                if (i + 1 < height)
                {
                    blue = blue + cimage[i + 1][j + 1].rgbtBlue;
                    green = green + cimage[i + 1][j + 1].rgbtGreen;
                    red = red + cimage[i + 1][j + 1].rgbtRed;
                    counter++;
                }
            }

            if (i - 1 >= 0)
            {
                blue = blue + cimage[i - 1][j].rgbtBlue;
                green = green + cimage[i - 1][j].rgbtGreen;
                red = red + cimage[i - 1][j].rgbtRed;
                counter++;
            }

            if (i + 1 < width)
            {
                blue = blue + cimage[i + 1][j].rgbtBlue;
                green = green + cimage[i + 1][j].rgbtGreen;
                red = red + cimage[i + 1][j].rgbtRed;
                counter++;
            }

            image[i][j].rgbtBlue = round((float)(blue + cimage[i][j].rgbtBlue) / counter);
            image[i][j].rgbtGreen = round((float)(green + cimage[i][j].rgbtGreen) / counter);
            image[i][j].rgbtRed = round((float)(red + cimage[i][j].rgbtRed)/ counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
