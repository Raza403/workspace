/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
 
 

 node* root;
 //Global variable to count words in the Dictionary
 int words = 0;
 
 /**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //opening dictionary file to read
  FILE *fp = fopen (dictionary, "r");
  if (fp == NULL)
  {
      return false;
  }
  //Allocatng memory for root pointer.
  root = calloc (sizeof (node),1);
  //running pointer
  node* cursor;
  cursor = root;
  //Loop to take chars untill EOF.
  for (int k = fgetc (fp); k != EOF; k = fgetc (fp) )
  {
      //For converting chars to its position in array
      int i = position(k);
      //If it is not end of word.
      if (k != '\n')
      {
          //If cursor->children[i] don't exist malloc these.
          if (cursor->children[i] == NULL)
          {
                cursor->children[i] = calloc (sizeof (node),1);
                if (cursor -> children[i] == NULL)
                {
                    return false;
                }
                cursor = cursor->children[i];
          }
          else
          {
              cursor = cursor -> children[i];
          }
      }
      else
      {
          //Word is complete.
          cursor -> isWord = true;
          //Count words
          words++;
          //Set cuersor again back to root.
          cursor = root;
      }
  }
  //Close file.
  fclose (fp);
  
    return true;
}

bool check(const char* word)
{
    int i = 0;
    node* cursor = root;
    while (cursor != NULL)
    {
        char c = word[i];
        if (c == '\0')
        {
            return cursor->isWord;
        }
        int p = position(c);
        cursor = cursor->children[p];
        i++;
    }
    return false;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    unloadfunction(root);
    return true;
}

int position (int a)
{
    int c = 0;
    if (isupper (a))
    {
         c = a-65;
         return c;
    }
    else if (islower(a))
    {
        c = a-97;
        return c;
    }
    else if (a == 39)
    {
        c = a-13;
        return c;
    }
    else 
    return -1;
}

void unloadfunction (node* cursor)
{
    for (int i = 0;i<27;i++)
    {
        if (cursor->children[i] != NULL)
        {
              unloadfunction(cursor->children[i]);
        }
        
    }
    free (cursor);
}

