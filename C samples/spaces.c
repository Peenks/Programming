#include <stdio.h>
#include <ctype.h>

int main() {
    char str1[100];
    char str2[100];
    
    printf("Enter the string: ");
    scanf("%[^\n]s", &str1);
    
    int j = 0;
    for(int i = 0; str1[i] != '\0'; i++){
        if(!isspace(str1[i])){
            str2[j++] = str1[i];
        }
    }
    
    str2[j] == '\0';
   
    
    printf("New String: %s", str2);
    
    return 0;
}