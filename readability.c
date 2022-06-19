#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float letter = count_letters(text);
    float word = count_words(text);
    float sentence = count_sentences(text);

    float L = (letter / word) * 100;
    float S = (sentence / word) * 100;
    int index = (0.0588 * L) - (0.296 * S) - 15.8;
    if (index < 0)
    {
        printf("Before grade 0\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letterCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}

int count_words(string text)
{
    int wordCount = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            wordCount++;
        }
    }
    return wordCount;
}

int count_sentences(string text)
{
    int sentenceCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}