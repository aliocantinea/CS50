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
    // run through hash function
    // go to that hash in table
    // strcasecmp which will compare case insensitively
        // cursor = table[hash]
        // cursor = cursor->next;
        //if cursor = NULL return false

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
    fopen(dictionary, "r");
    if (NULL)
    {
        fclose(dictionary);
        return false;
    }
    char *temp;
    //streams char * into *temp
    fscanf(dictionary, "%s",temp);
    if (feof(temp))
    {
    fclose(dictionary)
    return true;
    }
    //copy word to new node
    node *word = malloc(sizeof(node));
    if (word == NULL)
    {
        printf ("Could not load word.\n");
        fclose(dictionary);
        return false;
    }

    //strcpy(n->word, "Hello");
    //n->next = NULL;

    //hash temp node
    unsigned int


    //add to table
    //node->next = table[hash];
    //table[hash] = *node;

    // call size function to add counter

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // count how many words in table
    // either scan and count or add to counter when you add a word**
        //this would have to be a global var so it can keep track and since nothing is passed into this function


    //when does this get called? if it happens in speller.c it doesn't make sense to add it in each word in load

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // free memory
    // for n = N(table[max])
        //do while (table[n] != NULL)
        //{
            //temp = table[n];
            //table[n] = temp->next;
            //free(temp);
        //}
        // ++n;
    for (int i = 0; i > N; ++i)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = temp->next;
            free(temp);
        }
    }
    return true;
}
