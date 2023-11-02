#include<stdio.h>

int main()
{
    char x[150];int i,j;long long int res;
    while(1){
    	scanf("%s",&x);
    	if (x[0]=='0'&&x[1]=='\0') break;
		for (i=0;x[i]!='\0';i++);
		int c;
		next1:i--;
		if (i>7) {
			
			c=(x[i]-48)*5;x[i]='\0';
			j=i-1;
			x[j]-=c;
			j--;
			while (x[j+1]<48){
				x[j+1]+=10;x[j]--;
			}
			next2:j--;
			if (x[j+1]<48){
				x[j+1]+=10;x[j]--;goto next2;
			}else goto next1;
		}
		else {
			sscanf(x,"%lld",&res);
			printf("%d\n",!(res%17));
		}
    }
    return 0;
}


