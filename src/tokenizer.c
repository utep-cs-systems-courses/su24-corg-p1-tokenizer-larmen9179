#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  
  return (c == '\t' || c == ' ');
  
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){

  return (!(space_char(c)) && c != '\0');

}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){

  while(*str != '\0' && space_char(*str)){
    str++;
  }

  if(*str == '\0'){
    return 0;
  }

  return str;
  
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){

  while(*token != '\0' && non_space_char(*token)){
    token++;
  }

  return token;
  
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){

  int tokenCount = 0;
  
  while(*str != '\0' && token_start(str) != 0){
    str = token_terminator(token_start(str));
    //printf("%c", *str);
    //str = token_terminator(str);
    //printf("%c", *str);
    tokenCount++;
  }
  return tokenCount;
  
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){

  char *str = malloc(len + 1 * sizeof(char));
  char *strp = str;

  //iterates over the length of the string
  //updating the malloced values
  for(int i = 0;i < len;i++){
    *strp++ = *inStr++;
  }

  strp++;
  *strp = 0;

  //testing the old pointer to see if it now points to new characters
  for(int i = 0;i < len;i++){
    printf("%c", *str);
  }

  return str;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){

  char *p;
  char **pp = &p;

  p = "hello world";

  printf("%s", *pp);

  return pp;

  
}

/* Prints all tokens. */
void print_tokens(char **tokens){

}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  //have to free all the pointers before the poniter to pointero
  free(tokens);
}

int string_length(char *str){

  char *p = str;

  p = token_terminator(p);

  return p - str;
  
}
