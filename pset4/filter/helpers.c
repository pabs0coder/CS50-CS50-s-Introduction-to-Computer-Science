#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get average of rgd
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;
            int r = image[i][j].rgbtRed;
            float avgr = (float)(r + g + b) / 3;
            int avg = round(avgr);
            // set average rgb
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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
            // sepia algorithms
            float sr = (float) .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sg = (float) .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sb = (float) .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            // round value
            int rsr = round(sr);
            int rsg = round(sg);
            int rsb = round(sb);
            // between 0 - 255
            if (rsr > 255)
            {
                rsr = 255;
            }
            if (rsb > 255)
            {
                rsb = 255;
            }
            if (rsg > 255)
            {
                rsg = 255;
            }
            // set values
            image[i][j].rgbtRed = rsr;
            image[i][j].rgbtGreen = rsg;
            image[i][j].rgbtBlue = rsb;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE ib = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = ib;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //set rgbtriple copy
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x] = image[y][x];
        }
    }

    //individual pixels
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (y == 0 && x == 0)
            {
                //averaging neighbors
                float ar = round((float)(copy[1][1].rgbtRed + copy[0][1].rgbtRed + copy[1][0].rgbtRed + copy[0][0].rgbtRed) / 4);
                float ab = round((float)(copy[1][1].rgbtBlue + copy[0][1].rgbtBlue + copy[1][0].rgbtBlue + copy[0][0].rgbtBlue) / 4);
                float ag = round((float)(copy[1][1].rgbtGreen + copy[0][1].rgbtGreen + copy[1][0].rgbtGreen + copy[0][0].rgbtGreen) / 4);

                //setting avg
                image[0][0].rgbtRed = ar;
                image[0][0].rgbtBlue = ab;
                image[0][0].rgbtGreen = ag;
            }
            else if (y == 0 && x == width - 1)
            {
                //averaging
                float ar = round((float)(copy[1][width - 2].rgbtRed + copy[0][width - 2].rgbtRed + copy[1][width - 1].rgbtRed + copy[0][width -
                                         1].rgbtRed) / 4);
                float ab = round((float)(copy[1][width - 2].rgbtBlue + copy[0][width - 2].rgbtBlue + copy[1][width - 1].rgbtBlue + copy[0][width -
                                         1].rgbtBlue) / 4);
                float ag = round((float)(copy[1][width - 2].rgbtGreen + copy[0][width - 2].rgbtGreen + copy[1][width - 1].rgbtGreen + copy[0][width
                                         - 1].rgbtGreen) / 4);

                //setting avg
                image[0][width - 1].rgbtRed = ar;
                image[0][width - 1].rgbtBlue = ab;
                image[0][width - 1].rgbtGreen = ag;
            }
            else if (y == height - 1 && x == 0)
            {
                //averaging neighbors
                float ar = round((float)(copy[height - 1][1].rgbtRed + copy[height - 2][1].rgbtRed + copy[height - 2][0].rgbtRed + copy[height -
                                         1][0].rgbtRed) / 4);
                float ab = round((float)(copy[height - 1][1].rgbtBlue + copy[height - 2][1].rgbtBlue + copy[height - 2][0].rgbtBlue + copy[height -
                                         1][0].rgbtBlue) / 4);
                float ag = round((float)(copy[height - 1][1].rgbtGreen + copy[height - 2][1].rgbtGreen + copy[height - 2][0].rgbtGreen + copy[height
                                         - 1][0].rgbtGreen) / 4);

                //setting avg
                image[height - 1][0].rgbtRed = ar;
                image[height - 1][0].rgbtBlue = ab;
                image[height - 1][0].rgbtGreen = ag;
            }
            else if (y == height - 1 && x == width - 1)
            {
                //average
                float ar = round((float)(copy[height - 2][width - 1].rgbtRed + copy[height - 1][width - 2].rgbtRed + copy[height - 2][width -
                                         2].rgbtRed + copy[height - 1][width - 1].rgbtRed) / 4);
                float ab = round((float)(copy[height - 2][width - 1].rgbtBlue + copy[height - 1][width - 2].rgbtBlue + copy[height - 2][width -
                                         2].rgbtBlue + copy[height - 1][width - 1].rgbtBlue) / 4);
                float ag = round((float)(copy[height - 2][width - 1].rgbtGreen + copy[height - 1][width - 2].rgbtGreen + copy[height - 2][width -
                                         2].rgbtGreen + copy[height - 1][width - 1].rgbtGreen) / 4);

                //setting avg
                image[height - 1][width - 1].rgbtRed = ar;
                image[height - 1][width - 1].rgbtBlue = ab;
                image[height - 1][width - 1].rgbtGreen = ag;
            }


            else if (y == 0 && x != 0 && x != width - 1)
            {
                float ar = round((float)(copy[y + 1][x - 1].rgbtRed + copy[y][x - 1].rgbtRed + copy[y][x + 1].rgbtRed + copy[y + 1][x + 1].rgbtRed +
                                         copy[y + 1][x].rgbtRed + copy[y][x].rgbtRed) / 6);
                float ab = round((float)(copy[y + 1][x - 1].rgbtBlue + copy[y][x - 1].rgbtBlue + copy[y][x + 1].rgbtBlue + copy[y + 1][x +
                                         1].rgbtBlue +
                                         copy[y + 1][x].rgbtBlue + copy[y][x].rgbtRed) / 6);
                float ag = round((float)(copy[y + 1][x - 1].rgbtGreen + copy[y][x - 1].rgbtGreen + copy[y][x + 1].rgbtGreen + copy[y + 1][x +
                                         1].rgbtGreen +
                                         copy[y + 1][x].rgbtGreen + copy[y][x].rgbtRed) / 6);

                //setting avg
                image[y][x].rgbtRed = ar;
                image[y][x].rgbtBlue = ab;
                image[y][x].rgbtGreen = ag;
            }
            else if (y != 0 && y != height - 1 && x == 0)
            {
                float ar = round((float)(copy[y - 1][x].rgbtRed + copy[y - 1][x + 1].rgbtRed + copy[y][x + 1].rgbtRed + copy[y + 1][x + 1].rgbtRed +
                                         copy[y + 1][x].rgbtRed + copy[y][x].rgbtRed) / 6);
                float ab = round((float)(copy[y - 1][x].rgbtBlue + copy[y - 1][x + 1].rgbtBlue + copy[y][x + 1].rgbtBlue + copy[y + 1][x +
                                         1].rgbtBlue +
                                         copy[y + 1][x].rgbtBlue + copy[y][x].rgbtRed) / 6);
                float ag = round((float)(copy[y - 1][x].rgbtGreen + copy[y - 1][x + 1].rgbtGreen + copy[y][x + 1].rgbtGreen + copy[y + 1][x +
                                         1].rgbtGreen +
                                         copy[y + 1][x].rgbtGreen + copy[y][x].rgbtRed) / 6);

                //setting avg
                image[y][x].rgbtRed = ar;
                image[y][x].rgbtBlue = ab;
                image[y][x].rgbtGreen = ag;
            }
            else if (y != 0 && y != height - 1 && x == width - 1)
            {
                float ar = round((float)(copy[y - 1][x].rgbtRed + copy[y - 1][x - 1].rgbtRed + copy[y][x - 1].rgbtRed + copy[y + 1][x - 1].rgbtRed +
                                         copy[y + 1][x].rgbtRed + copy[y][x].rgbtRed) / 6);
                float ab = round((float)(copy[y - 1][x].rgbtBlue + copy[y - 1][x - 1].rgbtBlue + copy[y][x - 1].rgbtBlue + copy[y + 1][x -
                                         1].rgbtBlue +
                                         copy[y + 1][x].rgbtBlue + copy[y][x].rgbtRed) / 6);
                float ag = round((float)(copy[y - 1][x].rgbtGreen + copy[y - 1][x - 1].rgbtGreen + copy[y][x - 1].rgbtGreen + copy[y + 1][x -
                                         1].rgbtGreen +
                                         copy[y + 1][x].rgbtGreen + copy[y][x].rgbtRed) / 6);

                //setting avg
                image[y][x].rgbtRed = ar;
                image[y][x].rgbtBlue = ab;
                image[y][x].rgbtGreen = ag;
            }
            else if (y == height - 1 && x != width - 1 && x != 0)
            {
                float ar = round((float)(copy[y][x + 1].rgbtRed + copy[y - 1][x + 1].rgbtRed + copy[y][x - 1].rgbtRed + copy[y - 1][x - 1].rgbtRed +
                                         copy[y - 1][x].rgbtRed + copy[y][x].rgbtRed) / 6);
                float ab = round((float)(copy[y][x + 1].rgbtBlue + copy[y - 1][x + 1].rgbtBlue + copy[y][x - 1].rgbtBlue + copy[y - 1][x -
                                         1].rgbtBlue +
                                         copy[y - 1][x].rgbtBlue + copy[y][x].rgbtRed) / 6);
                float ag = round((float)(copy[y][x + 1].rgbtGreen + copy[y - 1][x + 1].rgbtGreen + copy[y][x - 1].rgbtGreen + copy[y - 1][x -
                                         1].rgbtGreen +
                                         copy[y - 1][x].rgbtGreen + copy[y][x].rgbtRed) / 6);

                //setting avg
                image[y][x].rgbtRed = ar;
                image[y][x].rgbtBlue = ab;
                image[y][x].rgbtGreen = ag;
            }

            else
            {
                float ar = round((float)(copy[y - 1][x - 1].rgbtRed + copy[y - 1][x].rgbtRed + copy[y - 1][x + 1].rgbtRed + copy[y][x - 1].rgbtRed +
                                         copy[y + 1][x + 1].rgbtRed + copy[y][x + 1].rgbtRed + copy[y + 1][x - 1].rgbtRed + copy[y + 1][x].rgbtRed +
                                         copy[y][x].rgbtRed) /
                                 9);
                float ab = round((float)(copy[y - 1][x - 1].rgbtBlue + copy[y - 1][x].rgbtBlue + copy[y - 1][x + 1].rgbtBlue + copy[y][x -
                                         1].rgbtBlue +
                                         copy[y + 1][x + 1].rgbtBlue + copy[y][x + 1].rgbtBlue + copy[y + 1][x - 1].rgbtBlue + copy[y + 1][x].rgbtBlue +
                                         copy[y][x].rgbtBlue) /
                                 9);
                float ag = round((float)(copy[y - 1][x - 1].rgbtGreen + copy[y - 1][x].rgbtGreen + copy[y - 1][x + 1].rgbtGreen + copy[y][x -
                                         1].rgbtGreen +
                                         copy[y + 1][x + 1].rgbtGreen + copy[y][x + 1].rgbtGreen + copy[y + 1][x - 1].rgbtGreen + copy[y + 1][x].rgbtGreen +
                                         copy[y][x].rgbtGreen) /
                                 9);

                //setting avg
                image[y][x].rgbtRed = ar;
                image[y][x].rgbtBlue = ab;
                image[y][x].rgbtGreen = ag;
            }
        }
    }
    return;
}
