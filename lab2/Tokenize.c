//Wap to tokenize an entered string.


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isKeyword(char *token)
{
	char keywords[][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", 
        "double", "else", "enum", "extern", "float", "for", "goto", "if", 
        "int", "long", "register", "return", "short", "signed", "sizeof", 
        "static", "struct", "switch", "typedef", "union", "unsigned", "void", 
        "volatile", "while"
    };
    
    int i;
    for(i=0;i<32;i++)
    {
    	if(strcmp(token, keywords[i])==0)
    	{
    		return true;
    	}
    }
    return false;
}

bool isOperator(char *token)
{
	char operators[][2] = {"+", "-", "*", "/", "%", "="};
    int i;
	for (i = 0; i < 6; i++) {
        if (strcmp(token, operators[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isIdentifier(char *token)
{
	int i;
	if (!isalpha(token[0]) && token[0] != '_') {
        return false;
    }
    for (i = 1; i < strlen(token); i++) {
        if (!isalnum(token[i]) && token[i] != '_') {
            return false;
        }
    }
    return true;
}

bool isConstant(char *token)
{
	int length = strlen(token),i;
    if (length == 0) return false;

    for (i = 0; i < length; i++) {
        if (!isdigit(token[i]) && token[i] != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    char str[] = "int hello = 5.6"; 
    char delimiter[] = " ";
    char *token;

    token = strtok(str, delimiter);

     while (token != NULL) {
        if (isKeyword(token)) {
            printf("Token: %s - Keyword\n", token);
        } else if (isOperator(token)) {
            printf("Token: %s - Operator\n", token);
        } else if (isConstant(token)) {
            printf("Token: %s - Constant\n", token);
        } else if (isIdentifier(token)) {
            printf("Token: %s - Identifier\n", token);
        } else {
            printf("Token: %s - Unknown\n", token);
        }
        token = strtok(NULL, delimiter);
    }

    return 0;
}
