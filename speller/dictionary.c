// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1170;

// Hash table
node *table[N];

// Word count
unsigned int wordcount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    printf("checking word: %s... ", word);

    // TODO
    // run through hash function
    unsigned int h = hash(word);
    //printf("Hash: %i... \n", h);
    // go to that hash in table
    node *check = malloc(sizeof(node));
    if (check == NULL)
    {
        printf("Could not create node\n");
        return false;
    }
    check = table[h];

    // strcasecmp which will compare case insensitively
        // cursor = table[hash]
        // cursor = cursor->next;
        //if cursor = NULL return false

    // hash doesn't already exist
    if (check == NULL)
    {
        printf("not in hash\n\n");
        return false;
    }
    do
    {
        printf("comparing word: %s to check->word %s\n", word, check->word);
        if (strcasecmp(word, check->word) == 0)
        {
            return true;
        }
        else
        {
        check = check->next;
        printf("check->next->word is: %s\n", check->word);
        }
    }
    while (check != NULL);

    free(check);
    printf("Check ended\n\n");
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // output should be between 0 and N - 1, inclusively

    // find length of word
    int len = strlen(word);
    // first - 'grave' so that a = 1 not 0 when multiplying
    int first = tolower(word[0] - '`');
    // - 1 so 'a' is 0-indexed
    unsigned int hash = (first * len) - 1;

    //smallest word possible 'a'
    // 1(a) * 1(length) = 1
    //longest z
    // 26(z) * 45(length) = 1170
    // 0-indexed -1 = between 0 and 1169
    //const unsigned int n = 1170

    //testing
    printf("\nhash for %s: %i...\n", word, hash);

    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open read file
    FILE *dict;
    dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open dictionary\n");
        fclose(dict);
        return false;
    }
    //malloc space for stream to write into
    char *temp = malloc(LENGTH + 1);
    if (temp == NULL)
    {
        fclose(dict);
        return false;
    }
    //streams char * into temp until EOF
    while (fscanf(dict, "%s", temp) != EOF)
    {
        //malloc node and get pointer for node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not create node\n");
            fclose(dict);
            return false;
        }

        //copy word from temp to node->word and set next to null
        strcpy(n->word, temp);
        n->next = NULL;

        //testing
        //printf("temp loaded '%s' to node->word '%s'\n", temp, n->word);

        //hash temp node
        unsigned int h = hash(temp);

        //add to table
        //if empty
        if (table[h] == NULL)
        {
            //make table = node
            table[h] = n;
            printf("new table->word: %s\n", table[h]->word);
        }
        //if full
        else
        {
            //node-> looks at table
            n->next = table[h];
            //testing
            //printf("node attached to list\n");

            table[h] = n;
            //testing
            printf("table attached to node->: %s\n", table[h]->word);
        }


        free(n);

        //add to global var for wordcount
        ++wordcount;
        //testing
        //printf("add word count\n");
    }
    free(temp);
    fclose(dict);

    //testing
    printf("Loaded and closed dictionary...\n");
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // count how many words in table
    // either scan and count or add to counter when you add a word**
        //this would have to be a global var so it can keep track and since nothing is passed into this function

    printf("give wordcount %i\n", wordcount);
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
    for (int i = 0; i < N; ++i)
    {
        while (table[i]->next != NULL)
        {
            node *temp = table[i]->next;
            table[i] = temp->next;
            free(temp);
        }

    }
    return true;
}
