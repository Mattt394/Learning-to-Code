/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"
#define APOSTROPHE 26
#define CHILDSIZE 27

//adds a character to the trie
typedef struct node
{
    bool is_word;
    struct node *children[27];
} node;
node *root;
unsigned int counter;

void t_addc(node **root, char index)
{
    //Parse values index
    int i;
    if (isalpha(index))
    {
        i = index - 'a';
    }
    if (index == '\'')
    {
        i = APOSTROPHE;
    }
    //create traversal node
    node *trav = NULL;

    //traverse the node
    trav = (*root)->children[i];

    //check for NULL
    if (trav == NULL)
    {
        node *d = malloc(sizeof(struct node));
        (*root)->children[i] = d;
        return;
    }

    //if node exists
    else
    {
        //already exists
        return;
    }
}

void t_clearnode(node *ptr)
{

    //set up previous node pointer
    if (ptr->is_word == false)
    {
        for (int i=0; i<CHILDSIZE; i++)
        {
            if (ptr->children[i] != NULL)
            {
                t_clearnode(ptr->children[i]);
            }
        }
    }

    if (ptr != NULL)
    {
        free(ptr);
    }

}

/**
 * Returns true if word is in dictionary else false.
 * OMG IT WORKS!!!!
 */
bool check(const char *word)
{
    //init traversal node
    node *ptrav = NULL;
    ptrav = root;

    //Iterate through the word
    int len = strlen(word);
    for (int i = 0; i<len; i++)
    {
        //lowercase please
        int c;
        if (isalpha(word[i]))
        {
            c = tolower(word[i]) - 'a';
        }
        if (word[i] == '\'')
        {
            c = APOSTROPHE;
        }

        //iterate through children
        ptrav = ptrav->children[c];
        if (ptrav == NULL)
        {
            return false;
        }
    }
    //found a word
    if (ptrav->is_word == true)
    {
        return true;
    }
    //or not
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 * DONE BITCHES
 */
bool load(const char *dictionary)
{
    // Write the trie
    root = malloc(sizeof(node));
    //initialise counter
    counter = 0;
    if (root == NULL)
    {
        fprintf(stderr, "Could not create root");
        return false;
    }

    // try to open dictionary (completed)
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Dictionary %s could not be opened\n", dictionary);
        return false;
    }

    node *ptrav = NULL;
    ptrav = root;

    //iterate through each word in dictionary (uncompleted)
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {


        // allow only alphabetical characters and apostrophes (no \0)
        if (isalpha(c))
        {
            //Add c to the trie
            int index = c - 'a';
            t_addc(&ptrav, c);
            ptrav = ptrav->children[index];
        }
        else if (c == '\'')
        {
            //Add ' to the trie
            int index = APOSTROPHE;
            t_addc(&ptrav, c);
            ptrav = ptrav->children[index];
        }
        // we must have found a whole word
        else if (c < 'a' || c > 'z')
        {
            //set is_word to true
            ptrav->is_word = true;
            // prepare for next word
            ptrav = root;
            //increment counter
            counter++;
        }
    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 * STILL NEED TO DO
 */
unsigned int size(void)
{
    // TODO

    return counter;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{

    t_clearnode(root);


    return true;
}
