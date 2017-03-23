// Find all of the words in the word list that have no vowels
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
    if (word[i] == 'a' || word[i]== 'e' || word[i] == 'i'
        || word[i] == 'o' || word[i] == 'u' || word[i] == 'y'){
        count++; } 
   }
        if(count <= 0){
          printf("%s \n", word); 
        } 
        count= 0; 
 }
 return 0;
}






