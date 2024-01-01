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
	printf("%s + %s = ",str1,str2);
		
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
	

	if(carry!=0)
		c[len++]=1;
	for(i=len-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}

//大数减法 
void subnum(char*str1,char*str2){
	memset(a,0,1000*sizeof(int));
    memset(b,0,1000*sizeof(int));
    memset(c,0,1000*sizeof(int));
	printf("%s - %s = ",str1,str2);
	
	int i,borrow=0;
	int len1=strlen(str1),len2=strlen(str2),len=max(len1,len2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';	
	
	//初步根据位数判断两数大小	
	if(len2>len1){ 
		printf("-");
		for(i=0;i<len;i++){
			c[i]=b[i]-a[i]-borrow;
			if(c[i]<0){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	else{
		for(i=0;i<len;i++){
			c[i]=a[i]-b[i]-borrow;
			if(c[i]<0&&i+1<len){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	//如果发现被减数小于减数，则重新计算，用减数减去被减数，输出负号 
	if(c[len-1]<0){
		printf("-");
		for(i=0;i<len;i++){
			c[i]=b[i]-a[i]-borrow;
			if(c[i]<0&&i+1<len){
				borrow=1;
				c[i]+=10;
			}
			else
				borrow=0;
		}
	}
	
	
	while(c[len-1]==0&&len>1)
		len--;
	for(i=len-1;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}

//大数乘法 
void mulnum(char*str1,char*str2) {
	memset(a,0,1000*sizeof(int));
    memset(b,0,1000*sizeof(int));
    memset(c,0,1000*sizeof(int));
	printf("%s * %s = ",str1,str2);
	
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
	for(;i>=0;i--)
		printf("%d",c[i]);
	printf("\n");
}


//大数除法 
void divnum(char*str1,char*str2){
    memset(a,0,1000*sizeof(int));
    memset(b,0,1000*sizeof(int));
    memset(c,0,1000*sizeof(int));
	printf("%s / %s = ",str1,str2);
	
	int i,j,tmp,tmp2=0,borrow=0,temp[1000]={0},temp2[1000]={0};
	int len1=strlen(str1),len2=strlen(str2);
	for(i=0;i<len1;i++)
		a[i]=str1[len1-1-i]-'0';
	for(i=0;i<len2;i++)
		b[i]=str2[len2-1-i]-'0';
	
	if(compare(a,b)<0){
		printf("0\n");
		return;
	}
	
	while(compare(a,b)>=0){			
		tmp=len1-len2;
		if(tmp==tmp2&&tmp>0) tmp--;
		tmp2=tmp;

        memset(temp2,0,1000*sizeof(int));
		for(i=len1-1;i>=tmp;i--)
			temp2[i]=b[i-tmp];
		copy(temp,a);
		
		if(compare(temp,temp2)<0) continue;
		for(j=1;;j++){
			borrow=0;
			for(i=tmp;i<len1;i++){
				temp[i]=a[i]-temp2[i]-borrow;
				if(temp[i]<0){
					borrow=1;
					temp[i]+=10;
				}
				else
					borrow=0;
			}
			
			len1=copy(a,temp);			
			c[tmp]=j;
			if(compare(temp,temp2)<0)
				break;
		}
	}
	
	for(i=999;c[i]==0;i--);
	for(;i>=0;i--) printf("%d",c[i]);
	printf("\n");
}

int main() {
	addnum("265151916516519419516","15616651622161651616");
	subnum("163165165161984116165","15454874487989819449");
	mulnum("999999999999999999999","999999999999999999999");
	divnum("16516498416516516191981916516165","12345678");
}