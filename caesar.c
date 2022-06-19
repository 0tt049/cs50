#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string plain2cypher(string plain, int key);

int main(int argc, string argv[])
{
    // Variable to store user keys
    string plaintext = "";

    if (argc != 2) // to check if command line argument is not equal to 2
    {
        printf("Usage: ./caesar key\n"); // print  "Usage: ./caesar key if not equal to 2"
        return 1;
    }

    else
    {
        string KEY = (argv[1]);
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
        if (atoi(KEY) > 0)
        {
            plaintext = get_string("Plaintext: ");
            printf("ciphertext: ");
            for (int i = 0, len = strlen(plaintext); i < len; i++)
            {
                if (isalpha(plaintext[i]) && islower(plaintext[i]))
                {
                    printf("%c", ((((plaintext[i] - 97) + atoi(KEY)) % 26) + 97));
                }

                else if (isalpha(plaintext[i]) && isupper(plaintext[i]))
                {
                    printf("%c", ((((plaintext[i] - 65) + atoi(KEY)) % 26) + 65));
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
    }

    // Cypher function iterate over letters. If its alphabetical it shifts the letter by "KEY" amount. %26 assures value will wrap over alphabet.
}
