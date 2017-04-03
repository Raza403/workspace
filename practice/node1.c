#include <stdio.h>
#include <stdlib.h>
//struct node.
 struct node
{
    int data;
    struct node* next;
};
//prototype of create node function
void create();
void display();
//Global variable of startlist.
struct node* startlist;
int main (void)
{
    //initially startlist pointer value is null
    startlist = NULL;
    create();
    display();
    return 0;
}



void create()
{

 struct node *newnode, *temp;
 //variable c for checking if you want to increase the list, initial value is "y"
  char k = 'y';
      
  while (k=='y' || k=='Y')
  {
      //if it is start of list
      if (startlist == NULL)
      {
          newnode = (struct node *)
          malloc (sizeof (struct node));
          printf ("please enter Int\n");
          scanf ("%d", &newnode->data);
          newnode -> next = NULL;
          startlist = newnode;
          temp = newnode;
        }
        // If list has already created
        else 
        {
            newnode = (struct node*)
          malloc (sizeof (struct node));
          printf ("please enter Int\n");
          scanf ("%d", &newnode->data);
          newnode-> next = NULL;
          temp ->next = newnode;
          temp = newnode;
        }
        // if want to increase the list reply with yes or no
        printf ("Want to enter more y/n?\n");
        scanf (" %c", &k);
  }
  printf ("Node is created\n");
}

void display()
{
    struct node *temp;
    temp = startlist;
    if (temp != NULL )
    {
        printf ("Data in the SLL is\n");
        while (temp != NULL)
        {
            printf ("%d, ", temp->data);
            temp = temp->next;
        }
    }
    else
    {
    printf ("list is null\n");
    }
}