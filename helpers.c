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
       for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average=round(( image[i][j].rgbtGreen +  image[i][j].rgbtBlue + image[i][j].rgbtRed )/3.0);

            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;
            image[i][j].rgbtRed=average;

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
     for (int right=width-1,left=0 ;right>left;left++,right--)
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
            int count = 0;
            int totalR=0,totalG=0,totalB=0;
            int rowCoords[] = {i-1,i,i+1};
            int colCoords[] = {j-1,j,j+1};
            
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    
                    int currRow = rowCoords[r];
                    int currCol = colCoords[c];
                    
                    if(currRow>=0&&currCol>=0&&currRow<height&&currCol<width)
                    {
                        RGBTRIPLE pixle=image[currRow][currCol];
                        
                        totalR += pixle.rgbtRed;
                        totalB += pixle.rgbtBlue;
                        totalG += pixle.rgbtGreen;
                        count++;
                    }
                }
            }
                 image[i][j].rgbtGreen = round(totalG/count);
            image[i][j].rgbtBlue = round(totalB/count);
            image[i][j].rgbtRed = round(totalR/count);
         
        }
    }
    return;
}
