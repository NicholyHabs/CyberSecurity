// NGH CMS 495
// make a 13-place rotation cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if(argc != 2){
        fprintf(stderr, "Usage: ./rot13 plaintextString \n");
        exit(1);
    }
    
    char *secretMessage;
    secretMessage = argv[1];
    int i = 0; 
 
  for(i = 0; strlen(secretMessage) > i; i++){
    if(secretMessage[i] < 'N'){
        secretMessage[i] += 13; 
    } 
    else{
        secretMessage[i] -= 13;
    }

 }
    printf("%s \n" , secretMessage);
    return 0;

}