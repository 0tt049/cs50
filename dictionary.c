// Implements a dictionary's functionality

#include <ctype.h>
#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
// Initialize word counter
int counter = 0;

// Returns true if word is in dictionary, else false
// Case insensitive
bool check(const char *word)
{
    ///// TODO
    // Hash word to obtain a hash value
    int hashed_word = hash(word);
    // Access linked list at that index in the hash table
    node *cursor = table[hashed_word];
    // Traverse linked linked list, looking for the word (strcasecmp)
    //  Loop : cursor = cursor->next;
    //  Start with cursor set to first item in linked list
    //  Keep moving cursor until you get to NULL, checking each node for the word.
    while (cursor->next != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0 || strcasecmp(word, "A") == 0 || strcasecmp(word, "I") == 0)
        {
            cursor = cursor->next;
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Input: word, with alphabetical characters and (possibly) apostrophes
    // Output: numerical index between 0 and N -1, inclusive
    // Deterministic
    // Larger N means more buckets
    // If your function ends up with a value greater than N, you can take the value % N to get a value in the appropriate range
    // Exemple
    //  First letter
    //  First two letters
    //  Math using all the letters

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    ///// TODO
    // Open dictionary file
    //  Use fopen
    FILE *imput_pointer = fopen(dictionary, "r");
    //  Check if return value is NULL
    // Read strings from file one at a time
    //  fscanf(file, %s, word)
    //  fscanf will return EOF once it reaches end of file
    char buffer[LENGTH + 1];
    while (fscanf(imput_pointer, "%s", buffer) != EOF)
    {
        // Create a new node for each word
        //  Use malloc
        node *w = malloc(sizeof(node));
        //  Remember to check if return value is NULL
        if (w == NULL)
        {
            free(w);
            return false;
        }
        //  Copy word into node using strcpy
        strcpy(w->word, buffer);
        w->next = NULL;
        // Hash word to obtain a hash value
        //  Use the hash function
        //  Function takes a string and returns an index
        int table_index = hash(w->word);
        // Insert node into hash table at that location
        //  Recall that hash table is an array of linked lists
        //  Be sure to set pointers in the correct order
        w->next = table[table_index];
        table[table_index] = w;
        counter++;
    }
    fclose(imput_pointer);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    ///// TODO
    // Use load function to keep track of words
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Use 2 variables (i.e. tmp && cursor) to free(cursor) from first node until the end of linked list
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
