#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void display(int wordArr[]){
    printf("Words Number ");
    for(int i=0;i<5;i++){
        if(wordArr[i]==1){
            printf("%d ",i+1);
        }
    }
    printf(" contain a digit");
}

void findDigit(char* input, int* wordArr){
   
    
    int i = 0;
    int j = 0;
    for(i = 0; input[i] != '\0'; i++){
        int flag = 1;
        if(isdigit(input[i]) != 0 && flag == 1){
            flag = 0;
            wordArr[j] = 1;
        } 
        if(isspace(input[i]) != 0){
            flag = 1;
            j++;
        }
    }
}

int main() {
    char input[100];
    int wordArr[5]={0,0,0,0,0};
   
    
    printf("Enter a string: ");
    fgets(input,100,stdin);
    
    findDigit(input, wordArr);
    display(wordArr);
    
    return 0;
}