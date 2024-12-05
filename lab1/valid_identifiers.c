//valid identifier
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char variable_name[100];
	printf("Enter a variable name: ");
	scanf("%s",&variable_name);
	printf("Entered string was %s\n",variable_name);
	char special_characters[10]={' ','#','!','@','%','^','*','&','(',')'};
	int i,j, flag=0;
	
	int len=strlen(variable_name);
	
	for(i=0;i<len;i++)
	{
		for(j=0;j<10;j++)
		{
			if(variable_name[i]==special_characters[j])
			{
				flag=1;
			}
		}
	}
	
	
	if(isdigit(variable_name[0]))
	{
		printf("A varible cannot start with a  digit\n");
	}
	else if(flag==1){
			printf("A varible cannot have a special character\n");
	}
	else
	{
		printf("valid identifier");
	}
	
}

//spaces newlines and tabs
#include <stdio.h>

int main() {
    char ch;
    int spaces = 0, tabs = 0, newlines = 0;

    printf("Enter a paragraph (Ctrl+Z to finish, press enter again to see results) :\n");

    // Read characters until EOF (Ctrl+D on Unix/Mac, Ctrl+Z on Windows)
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            spaces++;
        } else if (ch == '\t') {
            tabs++;
        } else if (ch == '\n') {
            newlines++;
        }
    }

    printf("Spaces: %d\n", spaces);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}

//keyword check
#include<stdio.h>
#include<string.h>
int main(){
	char identifier_name[100];
	printf("Enter an identifier: ");
	scanf("%s",&identifier_name);
	printf("Entered string was %s\n",identifier_name);
	char keywords[][10]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
	int i,j, flag=0;
	
	for(i=0;i<28;i++)
	{
		if(strcmp(identifier_name, keywords[i])==0)
		{
			flag=1;
			break;
		}
		
	}
	
	if(flag==1){
		printf("keyword entered");
	}
	else{
		printf("not a keyword");
	}
	
	
}

//checking integer constant
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char integer_constant[100];
	printf("Enter an identifier: ");
	scanf("%s",&integer_constant);
	printf("Entered number was %s\n",integer_constant);
	
	int len = strlen(integer_constant),i,flag=0;
	for(i=0;i<len;i++)
	{
		if(integer_constant[0]=='+' || integer_constant[0]=='-')
		{
			continue;
		}
		else if(!isdigit(integer_constant[i]))
		{
			flag=1;
			break;
		}
	}
	
	if(flag==0)
		printf("A valid integer");
	else
		printf("Not a valid integer");
}

