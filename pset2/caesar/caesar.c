// author: pabs0coder
// CS50 pset2 caesar
// Augost 2020

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[1])
{

    string key = argv[1];
    int i = 0;
    int k = atoi(key);


    while (key[i] != '\0')
    {
        // Validating the Key is number.
        if (argc != 2 || !isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");

            return 1;
        }
        else if (key == NULL || isspace(key[i]))
        {
            printf("Usage: ./caesar k\n");
            return 1;
        }
        i++;

    }

    // prompt user for a code to encrypt
    string code = get_string("plainstext: ");
    printf("ciphertext: ");
    for (int y = 0, n = strlen(code); y < n; y++)
    {
        //check if the letter is uppercase or lowercase
        // converting
        if islower(code[y])

                    printf("%c", (((code[y] + k) - 97) % 26) + 97);

            else if isupper(code[y])

                    printf("%c", (((code[y] + k) - 65) % 26) + 65);

                //if neither

        else

                    printf("%c", code[y]);
        }

        printf("\n");
    return 0;







}


