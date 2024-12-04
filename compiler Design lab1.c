#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a string is a constant
bool isConstant(char str[]) {
    int i = 0;
    int len = strlen(str);
    while (i < len) {
        if (!isdigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

bool isKeyword(char str[]) {
    char *keywords[4] = {"int", "char", "function", "bool"};
    for (int i = 0; i < 4; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(char str[]) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter the identifier: ");
    scanf("%s", str);

    if (isIdentifier(str) && !isKeyword(str) && !isConstant(str)) {
        printf("Correct identifier\n");
    } else {
        printf("Incorrect identifier\n");
    }

    return 0;
}
