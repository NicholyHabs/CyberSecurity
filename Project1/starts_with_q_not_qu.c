// Find all of the words in the word list that start with "q" but not "qu"
// DSM, 2014

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 64

int main(int argc, char* argv[]) {

  FILE* f = fopen("words.txt", "r");

  char word[MAX_LENGTH];

  while (fgets(word, MAX_LENGTH, f)) {
    if ((word[0] == 'q') & (word[1] != 'u')) {
      printf("%s", word);  
    }
  }
}
