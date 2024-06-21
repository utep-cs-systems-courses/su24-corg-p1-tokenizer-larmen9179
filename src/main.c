#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 10

int main(int argc, char **argv){

  int c;

  char inputLine[MAXLEN] = {0};

  printf("$ ");
  
  while((c = getchar()) != EOF){
    if(c == '\n'){
      putchar(c);
      printf("$ ");
    }
    else{
      putchar(c);
    }

    //testing space char methods
    //printf(" %d %d\n", space_char(c), non_space_char(c));

    //testing token start and terminator
    char *p = "Hello there everybody my name is chungus";
    printf("%c", *(token_start(p)));

    printf("%d", *(token_terminator(p)));

    printf("%d", count_tokens(p));

    
    
  }

  
}
