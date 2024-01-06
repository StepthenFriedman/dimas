#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[10000],b[10000],c[10000];

void mulnum(char*str1,char*str2) {
	memset(a,0,10000*sizeof(int));
    memset(b,0,10000*sizeof(int));
    memset(c,0,10000*sizeof(int));

	int i,j,k,carry=0,tmp;
	int len1=strlen(str1),len2=strlen(str2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';
	
	for(i=0;i<len1;i++) for(k=i,j=0;j<len2;j++,k++) c[k]+=a[i]*b[j];
	
	for(i=0;i<=k;i++) {
		c[i]+=carry;
		tmp=c[i];
		c[i]=tmp%10;
		carry=tmp/10;
	}
	
	for(i=k;c[i]==0;i--);
    str1[i+1]='\0';
    int len=i;
	for(;i>=0;i--)
        str1[len-i]=c[i]+'0';
}

int main() {
    int n,i;
    char *ipt1=(char*)malloc(100000),*ipt2=(char*)malloc(100000);
    while (~scanf("%s%s",ipt1,ipt2)){
        mulnum(ipt1,ipt2);
        printf("%s\n",ipt1);
        memset(ipt1,'\0',100000);
        memset(ipt2,'\0',100000);
    }
}