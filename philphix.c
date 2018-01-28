
#include "hashtable.h"
#include "philphix.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

HashTable *dictionary;

int main(int argc, char **argv){
  if(argc != 2){
    /* Note, you can print everything you want to standard error, it will be
       ignored by the autograder */
    fprintf(stderr, "Specify a dictionary\n");
    return 0;
  }
  fprintf(stderr, "Creating hashtable\n");
  dictionary = createHashTable(2255, &stringHash, &stringEquals);
  fprintf(stderr, "Loading dictionary %s\n", argv[1]);
  readDictionary(argv[1]);
  fprintf(stderr, "Dictionary loaded\n");
  fprintf(stderr, "Processing stdin\n");
  processInput();
  return 0;
}

/* Define a hash function */
unsigned int stringHash(void *s){
  char *string = (void *) s;
  /* Printing string is to prevent a compiler warning until you
     actually implement this function 
  fprintf(stderr, "need to implement stringHash%s\n", string);*/

  unsigned int hash = 5381;
  int c;

  while ((c = *string++)) {
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
    
  return hash;

  /*CITE: Hash function by Daniel Bernstein, found here: http://www.cse.yorku.ca/~oz/hash.html*/

  /* To suppress compiler warning until you implement this function, */
  /*return 0;*/
}


int stringEquals(void *s1, void *s2){
  fprintf(stderr, "You need to implement stringEquals");
  /* To suppress compiler warning until you implement this function */
  return 0;
}

void readDictionary(char *name){
  FILE *inputFile = fopen(name, "r");

  /* Printing the address of inputFile is to suppress compiler warning
     until you implement this function */
  fprintf(stderr, "You need to implement readDictionary %x\n", (unsigned int) inputFile);
}


void processInput(){
  fprintf(stderr, "You need to implement processInput\n");
}
