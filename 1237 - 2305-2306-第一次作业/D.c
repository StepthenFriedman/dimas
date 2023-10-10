#include <stdio.h>
int main(){
	char c[5];
	while (scanf("%s",&c)!=EOF){
		if (c[0]=='?'){
		    if (c[1]>'3'&c[1]!='?'){
		        c[0]='1';
		    }else{
		        c[0]='2';
		    }
		}
		if (c[1]=='?'&c[0]=='2'){c[1]='3';}
		if (c[1]=='?'&c[0]!='2'){c[1]='9';}
		if (c[3]=='?'){c[3]='5';}
		if (c[4]=='?'){c[4]='9';}
		printf("%s\n",c);
	}
	return 0;
}
