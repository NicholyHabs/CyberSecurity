// Print all of the words in the word list
// DSM, 2014

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 64

int main(int argc, char* argv[]) {

  FILE* f = fopen("words.txt", "r");

  char word[MAX_LENGTH];

  while (fgets(word, sizeof(word), f)) {
    printf("%s", word);
  }
}
