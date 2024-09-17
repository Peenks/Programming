#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isDigit(char* str){
    for(int i = 0; str[i] != '\0'; i++){
        if(!isdigit(str[i])){
            return 0;
        } else if(isspace(str[i])){
            return 0;
        }
    }
    
 return 1;
}


int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    str[strcspn(str, "\n")] = 0;
    
    if(isDigit(str) == 1){
        printf("The string contains only digits.");
    } else {
        printf("The string contains non-digit characters.");
    }
    
    return 0;
}