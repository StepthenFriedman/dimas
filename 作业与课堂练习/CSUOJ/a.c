#include<stdio.h>

int main()
{
	int len=0,i=0,j=0,u=0,v=0,w=0;
	char code[40];
	
	while(1)
	{
		for(len=0;;len++) 
		{
			scanf("%c",&code[len]);
			if(code[len]=='\n') break; 
		}
		i=0;j=0;u=0;v=0;w=0;
		
		if(len>=8)
		{
			for(len=len-1;len>0;len--)
			{
				if(code[len]>=48&&code[len]<=57) i++;
				if(code[len]>=65&&code[len]<=90) j++;
				if(code[len]>=97&&code[len]<=122) u++;
				if(code[len]==33||code[len]==35||code[len]==36||code[len]==42) v++;
				if(code[len]==64||code[len]==126) v++;
			}
			if(i>0) w++;
			if(j>0) w++;
			if(u>0) w++;
			if(v>0) w++;
			
			if(w>2)
			{
				printf("yes\n");
			} 
			else
			{
				printf("no\n");
			}
		}
		else printf("no\n");
	}
}