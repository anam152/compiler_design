#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


const char *keywords[] = {"int", "float", "if", "else", "while", "return", "for", "do", "break", "continue"};
const int keywordCount = 10;


const char *operators[] = {"+", "-", "*", "/", "=", "==", "<", ">", "<=", ">=", "!="};
const int operatorCount = 11;


const char delimiters[] = {';', ',', '(', ')', '{', '}', '[', ']', ' ', '\t', '\n'};


bool isKeyword(const char *str) {
    int i;
    for (i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}


bool isOperator(const char *str) {
    int i;
    for (i = 0; i < operatorCount; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return true;
        }
    }
    return false;
}


bool isDelimiter(char ch) {
    size_t i;
    for (i = 0; i < sizeof(delimiters) / sizeof(delimiters[0]); i++) {
        if (ch == delimiters[i]) {
            return true;
        }
    }
    return false;
}


bool isIdentifier(const char *str) {
    int i;
    if (!isalpha(str[0]) && str[0] != '_') {
        return false;
    }
    for (i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }
    return true;
}


bool isInteger(const char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}


bool isRealNumber(const char *str) {
    int i;
    int dotCount = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dotCount++;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return dotCount == 1; 
}


void classifyToken(const char *token) {
    if (strlen(token) == 0) {
        return; 
    }

    if (isKeyword(token)) {
        printf("'%s' is a keyword\n", token);
    } else if (isOperator(token)) {
        printf("'%s' is an operator\n", token);
    } else if (strlen(token) == 1 && isDelimiter(token[0])) {
        printf("'%s' is a delimiter\n", token);
    } else if (isInteger(token)) {
        printf("'%s' is an integer\n", token);
    } else if (isRealNumber(token)) {
        printf("'%s' is a real number\n", token);
    } else if (isIdentifier(token)) {
        printf("'%s' is an identifier\n", token);
    } else {
        printf("'%s' is not a valid token\n", token);
    }
}

// Tokenize 
void processInputString(const char *input) {
    char token[100];
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isDelimiter(input[i]) || isOperator((char[]){input[i], '\0'})) {
            if (j > 0) {
                token[j] = '\0'; 
                classifyToken(token);
                j = 0; 
            }

            
            if (!isspace(input[i])) {
                token[0] = input[i];
                token[1] = '\0';
                classifyToken(token);
            }
        } else {
            token[j++] = input[i];
        }
        i++;
    }

   
    if (j > 0) {
        token[j] = '\0';
        classifyToken(token);
    }
}


int main() {
    char input[200];
    printf("Enter a string to parse: ");
    fgets(input, sizeof(input), stdin); 

    
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    processInputString(input);

    return 0;
}

