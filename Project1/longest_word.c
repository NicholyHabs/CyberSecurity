// Find the longest word in the list
// NGH, 2016 CMS 495        

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define MAX_LENGTH 64

int main(int argc, char* argv[]) {

  FILE* f = fopen("words.txt", "r");

  char word[MAX_LENGTH];
  char longest[MAX_LENGTH] = "a";
  char *temp;
  while (fgets(word, MAX_LENGTH, f)) {
    if ((strlen(word) >= strlen(longest))) {
      temp =(char*)malloc(MAX_LENGTH);
      strcpy(temp, longest);
      strcpy(longest,word);
      strcpy(word, longest);
    }
  }
    printf("%s", longest);
  
  return 0;
}