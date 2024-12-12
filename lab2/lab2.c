#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if the given string is a keyword
bool isKeyword(const char *str) {
    const char *keywords[] = {"if", "else", "int", "double", "float", "true", "false"};
    size_t numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (size_t i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if the given string is an operator
bool isOperator(const char *str) {
    const char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "!="};
    size_t numOperators = sizeof(operators) / sizeof(operators[0]);

    for (size_t i = 0; i < numOperators; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if the given string is a valid identifier
bool validIdentifier(const char *str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }
    for (size_t i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }
    return true;
}

// Function to check if the given string is a real number
bool isRealNumber(const char *str) {
    bool hasDecimal = false;
    size_t len = strlen(str);

    if (len == 0) {
        return false;
    }

    for (size_t i = 0; i < len; i++) {
        if (!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
        if (str[i] == '.') {
            if (hasDecimal) {
                return false; // More than one decimal point
            }
            hasDecimal = true;
        }
    }
    return hasDecimal;
}

// Function to parse the input string and classify tokens
void parse(char str[]) {
    const char *delimiters = " ,;()[]{}";
    char *token = strtok(str, delimiters);

    while (token != NULL) {
       

        if (isKeyword(token)) {
            printf("%s is a keyword\n", token);
        } else if (isOperator(token)) {
            printf("%s is an operator\n", token);
        } else if (validIdentifier(token)) {
            printf("%s is an identifier\n", token);
        } else if (isRealNumber(token)) {
            printf("%s is a real number\n", token);
        } else {
            printf("%s is an invalid token\n", token);
        }

        token = strtok(NULL, delimiters);
    }
}

int main() {
    char str[100] = "if (a == true) float pi = 3.14;";
    parse(str);
    return 0;
}
