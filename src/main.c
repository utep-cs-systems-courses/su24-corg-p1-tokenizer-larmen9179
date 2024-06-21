#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 10

int main(int argc, char **argv){

  int c;

  char inputLine[MAXLEN];

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
    char *p = "Hello there everybody my name is chungus   ";
    printf("%c\n", *(token_start(p)));

    printf("%d\n", *(token_terminator(p)));

    printf("%d\n", count_tokens(p));

    printf("%d\n", string_length("snickerdoodle"));
  copy_string(p, string_length(p*)):
  }  
}
