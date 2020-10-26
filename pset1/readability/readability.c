#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letterscount = 0;
    int wordcount = 1;
    int sentencecount = 0;

//count words
    for (int i = 0; i < strlen(text); i++)
    {
        // check for letters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letterscount++;
        }
        // check for space
        else if (text[i] == ' ')
        {
            wordcount++;
        }
        // check for punctuation
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentencecount++;
        }
    }
// formula for grading
    float grade = 0.0588 * (100 * (float) letterscount / (float) wordcount) - 0.296 * (100 * (float) sentencecount / (float) wordcount) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}