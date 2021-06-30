#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    int coins=0;
        float change;
        do
        {
            change = get_float("Change Owe :");

        }
        while(change<=0);
        int toCents = round(change *100);
        while(toCents-25>=0)
        {
            toCents =toCents-25;
            coins++;

        }
        while(toCents-10>=0)
        {
            toCents = toCents - 10;
            coins++;
        }
        while (toCents - 5 >= 0)
        {
            toCents = toCents -5;
            coins++;
        }
        
        while (toCents -1 >= 0)
        {
            toCents = toCents -1;
            coins++;
        }
        printf("%i\n",coins);
      

}