#include <stdio.h>
#include <string.h>
#include <ctype.h>

int* findCurse(char* str, int* curse){
   int flag = 1;
   for(int i = 0; str[i] != '\0'; i++){
      if(str[i] == '*' && flag == 1){
          (*curse)++;
          flag = 0;
      }
      if(isspace(str[i])){
          flag = 1;
      }
   }
   
   return curse;
}




int main(){
    char str[100];
    int curse = 0;
    
    printf("Enter a string: ");
    fgets(str,100,stdin);
    
    
    findCurse(str,&curse);
    
    printf("Number of curse words: %d", curse);
    
    
    
    return 0;
}