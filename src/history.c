#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

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
    int strLen = string_length_full(str);
    newNode->str = copy_str(str, strLen);
    newNode->next = 0;
    list->head = newNode;
  }
  else{
    
    Item *currItem = list->head;

    while(currItem->next != 0){
      //testing the contents of each node
      currItem = currItem->next;
    }
    
    Item *newNode = malloc(sizeof(Item));
    int strLen = string_length_full(str);
    newNode->str = copy_str(str, strLen);
    newNode->next = 0;
    currItem->next = newNode;
  }
}
  
/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){

  int count = 1;
  
  if(list->head == 0){
    return "Nothing in the history yet...\n";
  }

  Item *currItem = list->head;

  while(currItem->next != 0 && count != id){
    currItem = currItem->next;
    count++;
  }

  if(count == id){
    return currItem->str;
  }

  return "The history doesn't have that item..."; 
}


/*Print the entire contents of the list. */
void print_history(List *list){

  int count = 1;
  
  if(list->head == 0){
    printf("Nothing in the history yet...\n");
  }
  else{

    Item *currItem = list->head;

    printf("%d. %s", count, currItem->str);

    while(currItem->next != 0){
      currItem = currItem->next;
      count++;
      printf("%d. %s", count, currItem->str);
    }
    
  }

}
/*Free the history list and the strings it references. */
void free_history(List *list){

  Item *currItem = list->head;
  Item *next;

  while(currItem != 0){
    next = currItem->next;
    free(currItem->str);
    free(currItem);
    currItem = next;
  }

  free(list);
  
}
