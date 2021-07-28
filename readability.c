#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int letters, words, sentences, i, len, intindex; 
    float index, avletters, avsentences;
    letters = 0;
    words = 1; //Spaces will be always n words - 1. The count of words must start in 1
    sentences = 0;
    
    string paragraph = get_string("Text: ");  //Prompt user text
    len = strlen(paragraph);
    
    for (i = 0; i <= strlen(paragraph); i++) //Loop to count the total of characters
    {
        if ((paragraph[i] >= 'a' && paragraph[i] <= 'z') || (paragraph[i] >= 'A' && paragraph[i] <= 'Z')) // Counts letters
        {
            letters++;
        }
        else if (paragraph[i] == ' ') //Counts words
        {
            words++;
        }
        else if ((paragraph[i] == '.') || (paragraph[i] == '?') || (paragraph[i] == '!'))// Counts sentences
        {
            sentences++;
        }
        
    }
    
    avletters = (100 * (float)letters) / (float)words;
    avsentences = (100 * (float)sentences) / (float)words;
    index = ((0.0588 * avletters) - (0.296 * avsentences)) - 15.8;
    intindex = round(index);   //intindex to convert the rounded index into an integer
    // round(index) function to round to the nearest integer
    
    //Grade intindex score and print output
    if (intindex < 1)
    {
        printf("Grade: Before Grade 1\n");
    }
    else if (intindex > 16)
    {
        printf("Grade: Grade 16+\n");
    }    
    else 
    {
        printf("Grade %i\n", intindex);
    }

    return 0;
}
