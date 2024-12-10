#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidInteger(char *str) {
    int i = 0;  
    
    // only sign is entered 
    if (*str == '\0' || (str[0] == '+' || str[0] == '-') && str[1] == '\0') {
        return 0; 
    }
    
    // first character is + or -, skip it
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    
    // remaining characters are all digits
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }

    return 1;  
}

int main() {
    char input[100];  
    	printf("			===   Program to check Valid Integer   ===\n\n");

    while (1) {
        printf("Enter a positive or negative integer: ");
        
        if (scanf("%s", input) == 1) {
           
            if (isValidInteger(input)) {
                printf("You entered a valid integer: %s\n", input);
        
            } else {
                printf("Invalid input. Please enter a valid positive or negative integer.\n ");
            }
        } else {
         
            while (getchar() != '\n');  
            printf("Invalid input. Please enter a valid positive or negative integer: ");
        }
    }

    return 0;
}

