#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1000],b[1000],c[1000];
 
int max(int a,int b){
	return a>b?a:b;
}

//比较两个数组形式数字大小 
int compare(int*num1,int*num2){
	int i,j;
	for(i=999;num1[i]==0;i--);
	for(j=999;num2[j]==0;j--);
	if(i<j)return -1;
	else if(i>j)return 1;
	else{
		for(;i>=0;i--){
			if(num1[i]>num2[i])
				return 1;
			else if(num1[i]<num2[i])
				return -1;
		}
		return 0;
	}
}

//将一个数组赋给另一个数组 
int copy(int*num1,int*num2){
	int i,j;
	for(i=0;i<1000;i++)
		num1[i]=0;
	for(i=999;num2[i]==0;i--);
	for(j=0;j<=i;j++)
		num1[j]=num2[j];
	return i+1;
}

//大数加法 
void addnum(char*str1,char*str2){
	memset(a,0,1000*sizeof(int));
    memset(b,0,1000*sizeof(int));
    memset(c,0,1000*sizeof(int));
		
	int i,carry=0;
	int len1=strlen(str1),len2=strlen(str2),len=max(len1,len2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';
	for(i=0;i<len;i++){
		c[i]=(a[i]+b[i]+carry)%10;
		carry=(a[i]+b[i]+carry)/10;
	}
	

	if(carry!=0) c[len++]=1;
    str1[len]='\0';
	for(i=len-1;i>=0;i--)
        str1[len-1-i]=c[i]+'0';
}

//大数乘法 
void mulnum(char*str1,char*str2) {
	memset(a,0,1000*sizeof(int));
    memset(b,0,1000*sizeof(int));
    memset(c,0,1000*sizeof(int));

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
    char *ipt1=(char*)malloc(10000),*ipt2=(char*)malloc(10000),*ipt3=(char*)malloc(10000);
    while (~scanf("%d",&n)){
        ipt1[0]='1',ipt1[1]='\0';
        ipt2[0]='0',ipt3[1]='\0';
        for (i=1;i<=n;i++){
            sprintf(ipt2,"%d",i);
            mulnum(ipt1,ipt2);
            addnum(ipt3,ipt1);
        }
        printf("%s\n",ipt3);
        memset(ipt1,'\0',10000);
        memset(ipt2,'\0',10000);
        memset(ipt3,'\0',10000);
    }
}