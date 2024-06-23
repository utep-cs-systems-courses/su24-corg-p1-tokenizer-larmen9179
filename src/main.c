#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 100

int main(int argc, char **argv){

  char input[MAXLEN];

 firstInput:
  while(1){

    printf("Type your option...\n");
    printf("t = tokenizer, h = history, q = quit\n");
    printf("$ ");
   
    char *inputcheck = fgets(input, MAXLEN, stdin);
    
    char *p = input;

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
      //testing tokenizer methods
      char *p = " Smelly fart big smelly fart stuff piss";

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
  printf("history implemenation goes here >\n");
  
  printf("Type your option for the history menu:\n");
  printf("! - Lists complete history\n");
  printf("!<number> - Lists a unique history item\n");
  printf("m - Go back to the main menu\n");
  printf("q - Quit\n");

 done:
  exit(0);
}
