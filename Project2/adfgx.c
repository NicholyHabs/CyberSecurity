// create a adfgx cipher  
// NGH CMS 495 2/9/16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 80


char polybiusSquare(int x){
    int array = x;   
    
   if (array == 0){
        return  'A';
   }
    else if (x == 1){
       return 'D';
    }
    else if(x == 2){
       return 'F' ;
    }
    else if(x == 3){
         return 'G' ;
    }
    else{
       return 'X' ;
        
    }
    
    return 0;
}



int main(int argc, char *argv[]) {
    
      if(argc != 2){
        fprintf(stderr, "Usage: ./adfgx plaintextString \n");
        exit(1);
    }
    
    char *secretMessage;
    secretMessage = argv[1];
    int sM = 0;
    char adfgx[MAX_LENGTH];
    
   
    int column = 0;
    char col; 
    int row = 0;
    char r;
    int v = 0; 
    int x = 1;
    // column, row 
                        //    0A    1D   2F   3G   4X 
    char polybius [5][5] = {{ 'P', 'H', 'Q', 'G', 'M' }, // 0 A
                            { 'E', 'A', 'Y', 'N', 'O' }, // 1 D
                            { 'F', 'D', 'X', 'K', 'R' }, // 2 F
                            { 'C', 'V', 'S', 'Z', 'W' }, // 3 G
                            { 'B', 'U', 'T', 'I', 'L' }, // 4 X
                         };
    
    for(sM = 0; strlen(secretMessage) > sM; sM++){
        for(column = 0; 5 >column; column++){      
        for(row = 0; 5 > row; row++){    
            if(polybius[row][column] == secretMessage[sM] ){
                r = polybiusSquare(row);
                col = polybiusSquare(column);
                
                adfgx[v] =  r;
                v+=2; 
                adfgx[x] = col;
                x+=2;
            }
        }
        }
    }
    
   // printf("%s \n", adfgx);

    ////////
    
    char columnarTranspostion[7][6];
    int counter = 0; 
    int rcT = 0;
    int colCT = 0;
    
    for (colCT = 0; colCT < 6; colCT++){
       for(rcT= 0; rcT<7; rcT++){
     
            columnarTranspostion[rcT][colCT] = adfgx[counter];
            counter++;
           // printf("%c ", columnarTranspostion[rcT][colCT]);
        }
       // printf("\n");
    }
    
    int rowFinal = 0;
    int keyColumn = 0;

    int key[7] = {6, 1, 4, 0, 2, 3, 5};
   
  while(keyColumn < 7){
   for(rowFinal= 0; rowFinal< 6; rowFinal++){
            printf("%c", columnarTranspostion[key[keyColumn]][rowFinal]);
        }
        keyColumn++;
    }
       printf("\n");
    
     
    return 0; 
}