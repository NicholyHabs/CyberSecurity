// NGH CMS 495 
// Project 3 
//write a dictionary based password cracker

#include <stdio.h>
#include <unistd.h>
#include <crypt.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 128
void print_usage_error(){
    printf("Usage: ./crack -i input -o output -l listFile (-m optional)\n");
    exit(1);
}

int main(int argc, char **argv) {
    char *inputFile;
    char *outputFile; 
    char *listFile; 
    int mangled = 0; 
    int option = 0; 
    if (argc < 7 || argc > 8){
        print_usage_error(); 
        exit(1);
    }
     
    while((option = getopt(argc, argv, "i:o:l:m")) != -1){
        switch (option){
            case 'i':
                // input file
                inputFile = optarg; 
                printf("%s\n", inputFile);
                    break;
            case 'o': 
                // ouput file
                outputFile = optarg;
                break;
            case 'l':
                // list file 
                listFile = optarg; 
              //  printf("%s", listFile);
                break;
            case 'm':
                // mangling optional 
                mangled = 1; 
                break;
            default:
                exit(1);
            
        }
    }
  
    FILE* list = fopen(listFile, "r" );
  
    char keyList[MAX_LENGTH];
    
    char *keys[45000];
    char *keysHashed[45000];
   
    char *users[100];
    char *hashes[100];
    FILE* f = fopen(inputFile, "r");
  
    char shadowLine[MAX_LENGTH * sizeof(char)];
    char *search = ":";
  
        struct element {
            char *userNames;
            char *hashWord;
        };
    char *userNames;
    char *hashWord;
   
    int i =0;
    int y = 0;
    int mCount;
    int x;
    int k =0;

    int length;
    int z = 0; 
    char num[32];
   
while(fgets(keyList, MAX_LENGTH, list)){
 
  if(mangled == 1){
    
      for(mCount = 0; mCount < 10; mCount++){
        char *salt = "$1$";   
       // char *hash = crypt(keyList, salt);
      keyList[strlen(keyList)-1 ]= '\0';
    
      sprintf(num, "%d", mCount);
      strcat(keyList, num);
      
      
     
      keys[i] = strdup(keyList);
      
      char *hash = crypt(keyList, salt);
       
      keysHashed[k] = strdup(hash);
      
      k++;
      i++;
      
    }
    length= 35260; 
  }
  else{
 
        keyList[strlen(keyList)-1 ]= '\0';
        char *salt = "$1$";   
        char *hash = crypt(keyList, salt); 
       // keyList[strlen(keyList)-1 ]= '\0';
        keys[i] = strdup(keyList);
        keysHashed[k] = strdup(hash);
        i++; 
        k++;
        length = i;
  }
 
} 
while(fgets(shadowLine, sizeof(shadowLine), f)){
          
      
       userNames = strtok(shadowLine, search);
      
       users[y]= strdup(userNames);
       //fputs(userNames, cracked);
       //fputs(" ", cracked);
       y++;
  
          hashWord = strtok(NULL, search);
         
           hashes[z] =strdup(hashWord);
           //fputs(hashWord, cracked);
           //fputs("\n", cracked);
           z++;
         
}
       
        
         
  FILE* cracked = fopen(outputFile, "w+");    
        
  for(x=0; x< 100; x++){
      //for(y = 0; y< 100; y++){
        for(z =0 ; z < length; z++){
      
        if(strcmp(hashes[x], keysHashed[z]) == 0){
            fputs(users[x], cracked);
            fputs(" ", cracked);
            fputs(hashes[x], cracked);
            fputs(" ", cracked);
            fputs(keys[z], cracked);
            fputs("\n", cracked);
        }  
        } 
 }
 


fclose(f);
fclose(cracked);



 return 0;

}