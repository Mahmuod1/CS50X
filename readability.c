#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int get_letters(string word);

int main(void)
{
    string name = get_string("enter your string : ");
    int numberOfLettersInString = get_letters(name);
    if (numberOfLettersInString < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (numberOfLettersInString > 15)
    {
        printf("Grade 16+\n");
    } 
    else
    {
        printf("Grade %i\n", numberOfLettersInString);
    }
}

int get_letters(string word)
{
    int whiteSpace1 = 0,
        sentence = 0;
    int numberOfLetters = 0;
    for (int i = 0, n = strlen(word) ; i < n ; i++)
    {
        if (isalpha(word[i]) && word[i] != '-')
        {
            numberOfLetters++;
             
        }
        if (isspace(word[i]))
        {
            whiteSpace1++;
            
        }
        if (word[i] == 46 || word[i] == 33 || word[i] == 63)
        {
            sentence++;
        }
  
         
    }
    whiteSpace1++;
    float L = numberOfLetters / (float) whiteSpace1 * 100;
    float S = sentence / (float) whiteSpace1 * 100;
    int index = round(0.0588 * L - 0.296 *  S  - 15.8);
    return index;
}