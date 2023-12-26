#include <stdio.h>

int gcd(int a,int b){return b?gcd(b,a%b):a;}

char upper(int n){return 'A'+n%26;}

char lower(int n){return 'a'+n%26;}

char number(int n){return '1'+n%9;}

void printbox(int len){
	if (len==1){printf("*\n\n");return;}
	int i,j,upperc=0,lowerc=0,numberc=0;
	for (i=0;i<len;i++){
		printf("%*c",len-i,'*');
		if (i==0||i==len-1) for (j=0;j<len-2;j++) putchar('*');
		else for (j=0;j<len-2;j++) putchar(upper(upperc++));
		putchar('*');
		for (j=1;j<i;j++) putchar(number(numberc++));
		if (i) putchar('*');
		putchar('\n');
	}
	for (i=0;i<len-2;i++){
		putchar('*');
		for (j=0;j<len-2;j++) putchar(lower(lowerc++));
		putchar('*');
		for (j=1;j<len-i-2;j++) putchar(number(numberc++));
		putchar('*');
		putchar('\n');
	}
	for (j=0;j<len;j++) putchar('*');
	printf("\n\n");
}

int main(){
	
	char ipt[200];int i,j,len,words;
	while (gets(ipt)!=NULL){
		words=1;
		for (i=0;ipt[i+1]!='\0';i++) if (ipt[i]==' '&&ipt[i+1]!=' ') words++;
		len=i+1;
		for (;i>-1;i--) if (ipt[i]==' ') printf("%s ",&ipt[i+1]),ipt[i]='\0';
		printf("%s ",&ipt[i+1]);
		putchar('\n');

		printbox(gcd(len,words));
	}
}