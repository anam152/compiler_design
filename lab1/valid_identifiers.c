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
