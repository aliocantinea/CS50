// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

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

// Word count
unsigned int wordcount = 0;

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

    // find length of word
    int len = strlen(word);
    int first = tolower(word[0]);
    // if first letter 'a' add 1 to times by len
    if (first == 0)
    {
        first++;
    }
    unsigned int hash = (first * len);

    //smallest word possible 'a'
    // 1 * 1 = 1
    //longest
    // 26(z) * 45(length) = 1170


    // returns 0 so that other functions work and for testing
    // return toupper(word[0]) - 'A';
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open read file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        fclose(dict);
        return false;
    }
    char temp[LENGTH + 1];
    //streams char * into temp until EOF
    while (fscanf(dict, "%s",temp) != EOF);
    {
        //copy word to new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf ("Could not load word.\n");
            fclose(dictionary);
            return false;
        }

        strcpy(n->word, temp);
        n->next = NULL;

        //hash temp node
        unsigned int h = hash(temp);

        //add to table
        n->next = table[h]->next;
        table[h] = *n;

        // add to global var for wordcount
        wordcount++;
    }
    fclose(dictionary)
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // count how many words in table
    // either scan and count or add to counter when you add a word**
        //this would have to be a global var so it can keep track and since nothing is passed into this function

    //when does this get called? if it happens in speller.c it doesn't make sense to add it in each word in load

    return wordcount;
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
