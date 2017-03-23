// Find all of the words in the list that have three sets
// of repeated letters 
// NGH 2016 CMS 495

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 64

int main(int argc, char* argv[]) {
int i = 0; 
int count = 0;
  FILE* f = fopen("words.txt", "r");

  char word[MAX_LENGTH];
 while (fgets(word, MAX_LENGTH, f)) {
   for(i = 0; strlen(word) > i; i++){
    if (word[i] == word[i+1] && word[i+2] == word[i+3] && word [i+4]== word[i+5]){
        count++; } 
   }
        if(count == 1){
          printf("%s \n", word); 
        } 
        count= 0; 
 }
 return 0;
}






