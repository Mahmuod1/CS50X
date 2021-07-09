#include "helpers.h"
#include <math.h>
// Convert image to grayscale

// int upperLeft(int i ,int j)
// {
//     return image[i-1][j-1];
// }
// int upperRight(int i , int j)
// {
//     return image[i-1][j+1];
// }
// int downRight(int i ,int j)
// {
//     return image[i+1][j+1];
// }

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
       for (int i = 0; i < height-1; i++)
    {
        for (int j = 0; j < width-1; j++)
        {
            int average=(( image[i][j].rgbtGreen +  image[i][j].rgbtBlue + image[i][j].rgbtRed ));

            image[i][j].rgbtGreen=round(average/3);
            image[i][j].rgbtBlue=round(average/3);
            image[i][j].rgbtRed=round(average/3);

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
         int spiaRed=round((.393 *  image[i][j].rgbtRed) +(.769  *  image[i][j].rgbtGreen) + (.189 *   image[i][j].rgbtBlue));
         int spiaGreen=round((.349 *  image[i][j].rgbtRed) +(.686  *  image[i][j].rgbtGreen) + (.168 *   image[i][j].rgbtBlue));
         int spiaBlue=round((.272 *  image[i][j].rgbtRed) +(.534  *  image[i][j].rgbtGreen) + (.131 *   image[i][j].rgbtBlue));
         if(spiaRed>255)
         {
             spiaRed=255;
         }
         if(spiaGreen>255)
         {
             spiaGreen=255;
         }
         if(spiaBlue>255)
         {
             spiaBlue=255;
         }
            image[i][j].rgbtGreen=spiaGreen;
            image[i][j].rgbtBlue=spiaBlue;
            image[i][j].rgbtRed=spiaRed;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int r = 0; r < height; r++){
     for (int right=width,left=0 ;right>left;left++,right--)
     {
         int temp= image[r][left].rgbtGreen;
         
         image[r][left].rgbtGreen=image[r][right].rgbtGreen;
      image[r][right].rgbtGreen=temp;
      temp= image[r][left].rgbtBlue;
          image[r][left].rgbtBlue=image[r][right].rgbtBlue;
          image[r][right].rgbtBlue=temp;
          temp=image[r][left].rgbtRed;
           image[r][left].rgbtRed=image[r][right].rgbtRed;
           image[r][right].rgbtRed=temp;
     }

        // Reset left and right after processing a row.
     
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtGreen=0;
            image[i][j].rgbtBlue=0;
            image[i][j].rgbtRed=0;
            
            if(i==0&&j==0)
            {
                int boxRed=round((image[i][j].rgbtRed+image[i+1][j+1].rgbtRed));
            }
        }
    }
    return;
}
