#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *headPtr = malloc(sizeof(List));

  headPtr->head = 0;

  return headPtr;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){

  if(list->head == 0){
    Item *newNode = malloc(sizeof(Item));
    newNode->str = str;
    newNode->next = 0;
    list->head = newNode;
  }
  else{
    Item *currItem = list->head;

    while(currItem != 0){
      //testing the contents of each node
      printf("%s", currItem->str);
      currItem = currItem->next;
    }
    Item *newNode = malloc(sizeof(Item));
    newNode->str = str;
    newNode->next = 0;
  }
}
  
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list);

/*Free the history list and the strings it references. */
void free_history(List *list);
