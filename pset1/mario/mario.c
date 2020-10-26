#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    
    do
    {
    height = get_int("Height?\n");
    }
    while (height >8 || height < 1);
    
    for (int i = 0; i < height; i++)
    {
        // Print " " (n - 1 - i) times
        for (int d = height - 1; d > i; d--)
        {
            printf(" ");
        } 

        // Print '#' (i + 1) times
        for (int h = -1; h < i; h++)
        {
            printf("#");
        } 
        printf("\n");
    }

}
