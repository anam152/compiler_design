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
