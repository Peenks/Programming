#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(char* str, int* spaceCount){
   *spaceCount = 0;
    
    for(int i = 0; str[i] != '\0'; i++){
        if(isspace(str[i])){
            (*spaceCount)++;
        }
    }
    
    return *spaceCount;
}


int main(){
    char str[100];
    int spaceCount;
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    
    if(countWords(str, &spaceCount)){
        printf("Number of words: %d", spaceCount);
    }
    
    
    return 0;
}