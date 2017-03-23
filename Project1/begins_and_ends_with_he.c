// Find the word that begins wiht "he" and 
// ends with "he"
// NGH 2016 CMS 495

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 64

int main(int argc, char* argv[]) {

  FILE* f = fopen("words.txt", "r");
  
 char word[MAX_LENGTH];
 while (fgets(word, MAX_LENGTH, f)) {
    int len = strlen(word);
    if ((word[0]=='h') & (word[1] == 'e' ) && ((word[len-3] == 'h') & (word[len-2]== 'e'))){
          printf("%s \n", word); 
        }
 }
 return 0;
}






