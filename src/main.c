#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLEN 100

int main(int argc, char **argv){

  int c;

  printf("$ ");
  
  while((c = getchar()) != EOF){
    if(c == '\n'){
      putchar(c);
      printf("$ ");
    }
    else{
      putchar(c);
    }
  }
}
