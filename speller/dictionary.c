// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // output should be between 0 and N - 1, inclusively




    // 
    // returns 0 so that other functions work and for testing
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open read file
    fopen;
    if (NULL)
    {
        fclose;
        return false;
    }
    do while (EOF);
    fscanf(file, "%s", word);


    //copy word to new node
            //malloc    node *n = malloc(sizeof(node));
            //check for NULL return false
            //strcpy(n->word, "Hello");
            //n->next = NULL;

    //hash temp node


    //add to table
        //node->next = table[hash];
        //table[hash] = *node;

    // TODO
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
