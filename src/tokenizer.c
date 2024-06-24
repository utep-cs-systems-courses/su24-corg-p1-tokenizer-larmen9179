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

  char *str = malloc((len + 1) * sizeof(char));
  char *strp = str;

  //iterates over the length of the string
  //updating the malloced values
  for(int i = 0;i < len;i++){
    *strp++ = *inStr++;
  }

  *strp = 0;

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

  //finding out how many tokens we need to malloc
  int numTokens = count_tokens(str);

  //pointing a pp to the allocated memory of char pointers
  char **tokenFinal = malloc((numTokens + 1) * sizeof(char *));

  char **tokenPtr = tokenFinal;
  
  for(int i = 0;i < numTokens;i++){
    //find the start of the next token
    str = token_start(str);
    
    //find that tokens length
    int length = string_length(str);

    //copy the token
    char *copyPtr = copy_str(str, length);

    //assign the current index in the pp to the pointer copy we just made
    tokenPtr[i] =  copyPtr;

    //find the terminator of the current token
    //this way we can find the next token if there is one
    str = token_terminator(str);
  }

  //set the last index to zero terminator
  tokenPtr[numTokens] = 0;
  
  return tokenFinal;
  
}

/* Prints all tokens. */
void print_tokens(char **tokens){

  int i = 0;

  putchar('\n');
  printf("Printing tokens...\n");
  
  while(tokens[i] != 0){
    printf("tokens[%d] = %s\n", i, tokens[i]);
    i++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  //have to free all the pointers before the pointer to pointer
  int i = 0;

  //freeing all the pointers
  while(tokens[i] != 0){
    free(tokens[i]);
    i++;
  }

  //freeing the null terminated space
  free(tokens[i]);
  //freeing the vector
  free(tokens);
}

int string_length(char *str){

  char *p = str;

  p = token_terminator(p);

  return p - str;
  
}

int string_length_full(char *str){

  int count = 0;
  
  while(*str++ != 0){
    count++;
  }

  return count;
}
