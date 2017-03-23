// Find all of the words in the word list that have no vowels
// NGH 2016 CMS 495

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 64

int main(int argc, char* argv[]) {

  FILE* f = fopen("words.txt", "r");

  char word[MAX_LENGTH];

  while (fgets(word, MAX_LENGTH, f)) {
      int i = 0; 
    if ((word[i] != 'a') & (word[i] != 'e')) &
        ((word[i] != 'i') & (word[i] != 'o')) &
        ((word[i] != 'u') & (word[i] != 'y')){
    int i++; 
      printf("%s", word);  
    }
  }
}
