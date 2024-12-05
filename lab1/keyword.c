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
