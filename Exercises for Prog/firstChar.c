#include <stdio.h>
#include <string.h>

int findChar(char* str, int c){
    for(int i = 0; str[i] != '\0'; i++){
        if(c == str[i]){
            return i;
        }
    }
    
    return -1;
}

int main(){
    char str[100];
    char c;
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    
    printf("Enter a character to find: ");
    scanf("%c", &c);
    
    int index = findChar(str,c);
    if(index != -1){
        printf("First occurrence of '%c' is at index %d", c, index);
    } else {
        printf("Character '%c' not found in the string", c);
    }

    return 0;
}