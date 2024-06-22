#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 50

int main(int argc, char **argv){

  char inputLine[MAXLEN];

  int c = 0;

 firstInput:
  while(c != EOF){

    printf("Type your option...\n");
    printf("t = tokenizer, q = quit\n");

    printf("$ ");
    c = getchar();

    //skipping newline for input options
    getchar();

    switch(c){
    case 'q':
      printf("Quitting...\n");
      goto done;
      break;
    case 't':
      //testing tokenizer methods
	
      //printf(" %d %d\n", space_char(c), non_space_char(c));
	
      char *p = "Hello there";

      printf("%c\n", *(token_start(p)));

      printf("%d\n", *(token_terminator(p)));

      printf("%d\n", count_tokens(p));

      printf("%d\n", string_length("snickerdoodle"));
    
      copy_str(p, string_length(p));

      printf("%d\n", string_length_full(p));
	
      break;
	
    }
    
    
  }

 done:
  exit(0);
}
