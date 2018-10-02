// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"

struct node
{
    bool end_string;
    struct node *next_char[26];
};
typedef node *root;
int wordCount=0;
// Returns true if word is in dictionary else false
bool check(const char *word)
{
        word="hello";
    // TODO
    return true;
}
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
   FILE *fp;
   fp=fopen (dictionary, "r");
   dictionary=malloc(sizeof(fp));
    // TODO
//if small dictionary is not inputted than return with default

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
