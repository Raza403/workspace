#include <stdio.h>
#include <cs50.h>

typedef struct node
{
    unsigned int n ;
    struct node* next;
}
node;
bool search (int n, node* list);
int main (void)
{
    bool search (int n, node* list);
   
}

 bool search (int n, node* list)
    {
        node* ptr = list;
        while (ptr != NULL)
        {
            if (ptr->n == n)
            {
                return true;
            }
            else
            ptr = ptr-> next;
        }
        return false;
    }

