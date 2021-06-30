#include <cs50.h>
#include <stdio.h>
void getPopulationSize(void);
int main(void)
{
    
    getPopulationSize();
}

void getPopulationSize(void)
{
    int startSize = 0;
    
    while (startSize < 9)
    {
        startSize = get_int("start size :");
    }
    int endSize = 0;
    
    while (endSize < startSize)
    {
        endSize = get_int("end Size :");
    }
    
    int years = 0;
    
    while (endSize > startSize)
    { 
        startSize = startSize + (startSize / 3) - (startSize / 4);
        years++;
    }
 
    printf("Years: %i\n", years);
    
}