#include <cs50.h>
#include <stdio.h>
void getAlignetBlocks(int height);
int main (void)
{
    int height = 0;
    do{
        height = get_int("height : ");
    }
    while(height<=0||height>8);
        getAlignetBlocks(height);
}

void getAlignetBlocks(int height)
{

     for(int i=1;i<=height;i++)
    {
        for(int j=height;j>i;j--)
        {
            printf(" ");
        }
        for(int k=i-i;k<i;k++)
        {
            printf("#");
        }
        printf("\n");
    }
}