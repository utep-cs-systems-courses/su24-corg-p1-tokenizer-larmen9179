#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 100

int main(int argc, char **argv){

  char input[MAXLEN];
  char *inputcheck;
  char *p;
  List *headPtr = init_history();

 firstInput:
  while(1){

    printf("Type your option...\n");
    printf("t = tokenizer, h = history, q = quit\n");
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

      char **tokens = tokenize(p);

      print_tokens(tokens);

      free_tokens(tokens);

      add_history(headPtr, "fart");

      //printf("%s\n", headPtr->head->str);
	
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
  printf("history implemenation goes here >\n");
  putchar('\n');
  printf("Type your option for the history menu:\n");
  printf("! - Lists complete history\n");
  printf("!<number> - Lists a unique history item\n");
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
      printf("handle specific history here\n");
    }
    else{
      printf("handle full history here\n");
    }
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
