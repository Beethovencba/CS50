#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float mediaRGB;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mediaRGB = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(mediaRGB);
            image[i][j].rgbtGreen = round(mediaRGB);
            image[i][j].rgbtRed = round(mediaRGB);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float new_rgb[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int n = 0; n < 3; n++)
            {
                new_rgb[n] = 0;
            }
            new_rgb[0] = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            new_rgb[1] = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            new_rgb[2] = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            if (new_rgb[0] < 255.0)
            {
                image[i][j].rgbtRed = round(new_rgb[0]);
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            if (new_rgb[1] < 255.0)
            {
                image[i][j].rgbtGreen = round(new_rgb[1]);
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (new_rgb[2] < 255.0)
            {
                image[i][j].rgbtBlue = round(new_rgb[2]);
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            tmp[i][(width - 1) - j].rgbtBlue = image[i][j].rgbtBlue;
            tmp[i][(width - 1) - j].rgbtGreen = image[i][j].rgbtGreen;
            tmp[i][(width - 1) - j].rgbtRed = image[i][j].rgbtRed;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    free(tmp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    float average[3];
    float divider;

    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            divider = 0;
            for (int n = 0; n < 3; n++)
            {
                average[n] = 0;
            }
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if (i + y >= 0 && i + y < height)
                    {
                        if (j + x >= 0 && j + x < width)
                        {
                            average[0] = image[i + y][j + x].rgbtBlue + average[0];
                            average[1] = image[i + y][j + x].rgbtGreen + average[1];
                            average[2] = image[i + y][j + x].rgbtRed + average[2];
                            divider++;
                        }
                    }
                }

            }

            if (average[0] != 0)
            {
                tmp[i][j].rgbtBlue = round(average[0] / divider);
            }
            if (average[1] != 0)
            {
                tmp[i][j].rgbtGreen = round(average[1] / divider);
            }
            if (average[2] != 0)
            {
                tmp[i][j].rgbtRed = round(average[2] / divider);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    free(tmp);
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    double sum[6];
    double root_square;
    int multiplier;
    for (int i = 0; i < height; i++)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            for (int n = 0; n < 6; n++)
            {
                sum[n] = 0;
            }
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    multiplier = x;
                    if (y == 0)
                    {
                        multiplier = x * 2;
                    }

                    if (i + y >= 0 && i + y < height)
                    {
                        if (j + x >= 0 && j + x < width)
                        {
                            //Gx
                            sum[0] = (image[i + y][j + x].rgbtBlue * multiplier) + sum[0];
                            sum[1] = (image[i + y][j + x].rgbtGreen * multiplier) + sum[1];
                            sum[2] = (image[i + y][j + x].rgbtRed * multiplier) + sum[2];
                        }

                    }
                    if (i + x >= 0 && i + x < height)
                    {
                        if (j + y >= 0 && j + y < width)
                        {
                            //Gy
                            sum[3] = (image[i + x][y + j].rgbtBlue * multiplier) + sum[3];
                            sum[4] = (image[i + x][y + j].rgbtGreen * multiplier) + sum[4];
                            sum[5] = (image[i + x][y + j].rgbtRed * multiplier) + sum[5];
                        }

                    }


                }
                root_square = sqrt(pow(sum[0], 2) + pow(sum[3], 2));
                if (root_square < 256)
                {
                    tmp[i][j].rgbtBlue = round(root_square);
                }
                else
                {
                    tmp[i][j].rgbtBlue = 255;
                }
                root_square = sqrt(pow(sum[1], 2) + pow(sum[4], 2));
                if (root_square < 256)
                {
                    tmp[i][j].rgbtGreen = round(root_square);
                }
                else
                {
                    tmp[i][j].rgbtGreen = 255;
                }
                root_square = sqrt(pow(sum[2], 2) + pow(sum[5], 2));
                if (root_square < 256)
                {
                    tmp[i][j].rgbtRed = round(root_square);
                }
                else
                {
                    tmp[i][j].rgbtRed = 255;
                }
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    free(tmp);
    return;
}
