#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isConstant(char input[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char input[100];

    printf("Enter something: ");
    scanf("%s", input); 
    if (input[0] == '"' && input[strlen(input) - 1] == '"') {
        printf("It is a string.\n");
    }
    
    else if (isConstant(input)) {
        printf("It is a constant.\n");
    }
    
    else {
        printf("It is neither a string nor a constant.\n");
    }

    return 0;
}
