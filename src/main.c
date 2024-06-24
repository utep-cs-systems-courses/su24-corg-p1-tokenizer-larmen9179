#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 100

int main(int argc, char **argv){

  char input[MAXLEN];
  char inputTwo[MAXLEN];
  char *inputcheck;
  char *p;
  List *headPtr = init_history();

 firstInput:
  while(1){

    printf("Type your option...\n");
    printf("t = Tokenizer, h = History, q = Quit\n");
    printf("$ ");
   
    inputcheck = fgets(input, MAXLEN, stdin);
    
    p = input;

    //removing newline from input
    while(*p != '\0'){
      if(*p == '\n'){
	*p = '\0';
	break;
      }
      p++;
    }

    switch(input[0]){
    case 'q':
      printf("Quitting...\n");
      goto done;
      break;
    case 't':
      printf("Enter in your string to tokenize:\n");
      printf("$ ");
      
      inputcheck = fgets(input, MAXLEN, stdin);
      
      char *p = input;

      printf("Would you like to add your string to the history? \n");
      printf("y = Yes, n = No\n");
      printf("$ ");

      inputcheck = fgets(inputTwo, MAXLEN, stdin);

      while(inputTwo[0] != 'y' && inputTwo[0] != 'n'){
	printf("That input isn't recognized... Try again\n");
	printf("y = Yes, n = No\n");
	printf("$ ");

	inputcheck = fgets(inputTwo, MAXLEN, stdin);
      }

      if(inputTwo[0] == 'y'){
	add_history(headPtr, p);
      }

      char **tokens = tokenize(p);

      print_tokens(tokens);

      free_tokens(tokens);
	
      break;
    case 'h':
      goto history;
      break;
    case '\0':
      goto firstInput;
      break;
    default:
      printf("That input isn't recognized... Try again\n");
      break;
    }
  
  }
  
 history:
  putchar('\n');
  printf("Type your option for the history menu:\n");
  printf("! - Lists complete history\n");
  printf("!<number> - Lists a unique history item\n");
  printf("c - Clears your current history\n");
  printf("m - Go back to the main menu\n");
  printf("q - Quit\n");
  putchar('\n');
  printf("$ ");
  
  inputcheck = fgets(input, MAXLEN, stdin);

  p = input;
  
  while(*p != '\0'){
      if(*p == '\n'){
	*p = '\0';
	break;
      }
      p++;
  }
  
  switch(input[0]){
  case '!':
    if(input[1] != '\0'){
      printf("%s", get_history(headPtr,input[1] - '0'));
    }
    else{
      print_history(headPtr);
    }
    goto history;
    break;
  case 'c':
    free_history(headPtr);
    headPtr = init_history();
    printf("History cleared...returning...\n");
    goto history;
    break;
  case 'm':
    goto firstInput;
    break;
  case 'q':
    goto done;
    break;
  default:
    printf("That input isn't recognized... Try again\n");
    goto history;
    break;
  }

 done:
  exit(0);
}
