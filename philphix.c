
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
  /*fprintf(stderr, "You need to implement stringEquals");*/
  /* To suppress compiler warning until you implement this function */
  char *str1 = (void *) s1;
  char *str2 = (void *) s2;
  int diff;

  diff = strcmp(str1, str2);

  if (diff == 0) { /* The strings are equal. */
    return diff;
  } else { /* The strings are not equal. */
    return 0;
  }

}

void readDictionary(char *name){
  FILE *inputFile = fopen(name, "r");

  if (inputFile == NULL) {
    fprintf(stderr, "Error opening dictionary file.");
    return;
  }

  while (readNextPair(inputFile) != 0) {
    fprintf(stderr, "NEW LINE CALL");
  }
  /* Printing the address of inputFile is to suppress compiler warning
     until you implement this function */
  /*fprintf(stderr, "You need to implement readDictionary %x\n", (unsigned int) inputFile);*/

}

int readNextPair(FILE *inputFile) { /* Read next key, value pair and enter into hashtable.  Return 0 if EOF and 1 if not. */
  /*FILE *inputFile = fopen(name, "r");*/
  const int BUFF_LEN = 2;
  int large_buff_len = 8;

  int curr_buff_pos = 0;

  char charbuff[BUFF_LEN];
  char large_charbuff[large_buff_len];


  while (fgets(charbuff, BUFF_LEN, inputFile) != NULL) {
    /*fprintf(stderr, charbuff);*/
    if (charbuff[0] == '\n') {
      return 1;
    } else {
      fprintf(stderr, charbuff);
    }
    fprintf(stderr, "\n");
  }

   fclose(inputFile);
   return 0;
}


void processInput(){
  fprintf(stderr, "You need to implement processInput\n");
}
