// Find all of the words in the list that have three sets
// of repeated letters 
// NGH 2016 CMS 495

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 64


int main(int argc, char* argv[]) {

  FILE* f = fopen("words.txt", "r");
  char word[MAX_LENGTH];
  char *temp;
  char reverse[MAX_LENGTH];
 while (fgets(word, MAX_LENGTH, f)) {
     word[strlen(word)-1 ]= '\0';
     int i = 0;
     int length = strlen(word)-1;
      temp =(char*)malloc(MAX_LENGTH);
      strcpy(temp, reverse);
      strcpy(reverse,word);
      strcpy(word, reverse);
    while(i< length){
        *temp = reverse[i]; 
        reverse[i] = reverse[length];
        reverse[length] = *temp;
        i++;
        length--;
    }
   if(strcmp(word,reverse) == 0){
      printf("%s \n", word); 
    } 
 }
 return 0;
}
