#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string plain2cypher(string plain, int key);

int main(int argc, string argv[])
{
    // Variable to store user keys
    string KEY = (argv[1]);
    int INTKEY = atoi(KEY);
    string plaintext = "";

    // Check if user provided only 1 argument &&
    if (argc != 2)
    {
        printf("Please insert a valid key.\n");
        return 1;
    }
    else
    {
        // Check if key is a number
        for (int i = 0, len = strlen(KEY); i < len; i++)
        {
            if (isdigit(KEY[i]))
            {
            }
            else
            {
                printf("Key must be a number\n");
                return 1;
            }
        }
        // Check if number is positive && get plaintext.
        if (INTKEY > 0)
        {
            plaintext = get_string("Plaintext: ");
        }
    }

    // Cypher function iterate over letters. If its alphabetical it shifts the letter by "KEY" amount. %26 assures value will wrap over alphabet.
    printf("cyphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]) && islower(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 97) + INTKEY) % 26) + 97));
        }

        else if (isalpha(plaintext[i]) && isupper(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 65) + INTKEY) % 26) + 65));
        }
        // If letter is not alphabet just print as is.
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
