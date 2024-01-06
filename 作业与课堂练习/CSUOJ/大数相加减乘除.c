//阶乘  2568对应1000
#include<stdio.h>
#include<string.h>
#define MAXIUM 2568

int main(){
    int n,i,j,up,temp;
    while(scanf("%d",&n)!=EOF){
	int a[10000]={0};a[0]=1;
    for(i=2;i<=n;i++){
        for(up=0,j=0;j<MAXIUM;j++){
            temp=a[j]*i+up;
            a[j]=temp%10;
            up=temp/10;
        }
    }
    for(i=j;i>=0;i--){
        if(a[i]!=0){
            for(i;i>=0;i--){
                printf("%d",a[i]);
            }
			printf("\n");
			continue;
        }
    }
	}
    return 0;
}

//加法
#include<stdio.h>
#include<string.h>
#define MAX 100000

int main(){
    int a[10000]={0},b[10000]={0};
    char buffer[10000]={0};
    int i,j,up,temp;
    scanf("%s",buffer);
    int s1=strlen(buffer);
    for(temp=0,i=s1-1;i>=0;i--){
        a[temp++]=buffer[i]-'0';
    }
    scanf("%s",buffer);int s2=strlen(buffer);
    for(temp=0,i=s2-1;i>=0;i--){
        b[temp++]=buffer[i]-'0';
    }
    int maxium=(s1>s2)?s1:s2;
    for(i=0;i<maxium;i++){
        temp=a[i]+b[i]+up;
        a[i]=temp%10;
        up=temp/10;
    }
    for(i=maxium;i>=0;i--){
        if(a[i]!=0){
            for(i;i>=0;i--){
                printf("%d",a[i]);
            }
        }
    }
    return 0;
}

//乘法
#include<stdio.h>
#include<string.h>
#define N 5000000

int main(){
	int i,j,L[N];
	char m[N], n[N];
	while(scanf("%s",m)!=EOF){
        scanf("%s",n);
	int len1=strlen(m);
	int len2=strlen(n);
	memset(L,0,sizeof(L));
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
			L[i+j]+=(m[len1-i-1]-'0')*(n[len2-j-1]-'0');
	for(i=0;i<len1+len2;i++)
		if(L[i]>=10){
			L[i+1]+=L[i]/10;
			L[i]%=10;
		}
	while(L[i] == 0)i--;
	while(i >= 0)printf("%d", L[i--]);
    printf("\n");
    }
	return 0;
}

//减法
#include<stdio.h>
#include<string.h>
#define M 100005

char s1[M],s2[M],s[M];
int  a[M],b[M],c[M];

void ss(char s1[],char s2[],int n,int m){
    int i,j,a[M],b[M];
    for(i=0; i<n; i++)
        a[i]=s1[n-i-1]-'0';
    for(i=0; i<m; i++)
        b[i]=s2[m-i-1]-'0';
    for(i=0; i<n; i++)
        c[i]=a[i]-b[i];
    for(i=0;i<n;i++)
      if(c[i]<0){
            while(c[i]<0){
              c[i+1]=c[i+1]-1;
              c[i]+=10;
            }
        }
}

int main(){
    int n,m,i,j,k,kk;
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    while(~scanf("%s%s",s1,s2))
    {
        n=strlen(s1);
        m=strlen(s2);
        if(n>m)ss(s1,s2,n,m);
        else if(n<m){
            printf("-");
            ss(s2,s1,m,n);
        }
        else{k=strcmp(s1,s2); 
            if(k==0){
                printf("0\n");
                continue;
            }
            else if(k>0)
                ss(s1,s2,n,m);
            else{
                printf("-");
                ss(s2,s1,m,n);
            }
        }
        if(n>m) kk=n;
        else kk=m;
        while(c[kk]==0)kk--;
        for(i=kk;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");
    }
    return 0;
}

//除法
#include<stdio.h>  
#include<string.h> 
#define N 5000000

char a[N],b[N];
int x[N],y[N],z[N]; 
int digit;

void sub(int x[],int y[],int len1,int len2){  
    int i;  
    for(i=0;i<len1;i++){  
        if(x[i]<y[i]){  
            x[i]=x[i]+10-y[i];  
            x[i+1]--;  
        }  
        else  x[i]=x[i]-y[i];  
    }  
    for(i=len1-1;i>=0;i--){  
        if(x[i]){   
            digit=i+1;  
            break;           
        }   
    }  
}  

int judge(int x[],int y[],int len1,int len2){  
    int i;  
    if(len1<len2)
        return -1;  
    if(len1==len2) {  
        for(i=len1-1;i>=0;i--)  {  
            if(x[i]==y[i])  
                continue;  
            if(x[i]>y[i])  
                return 1;  
            if(x[i]<y[i])
                return -1;  
        }  
        return 0; 
    }     
}

int main()  
{  
    int i,j=0,k=0,temp;  
    int len1,len2,len;
    while(~scanf("%s %s",a,b)){  
        len1=strlen(a);
        len2=strlen(b);
        for(i=len1-1,j=0;i>=0;i--)
            x[j++]=a[i]-'0';   
           
        for(i=len2-1,k=0;i>=0;i--)  
            y[k++]=b[i]-'0';              
        if(len1<len2) 
            puts(a);   
        else  {  
            len=len1-len2; 
            for(i=len1-1;i>=0;i--){  
                if(i>=len)  
                    y[i]=y[i-len];  
                else  
                    y[i]=0;  
            }  
            len2=len1;      
            digit=len1;
            for(j=0;j<=len;j++){  
                z[len-j]=0;  
                while(((temp=judge(x,y,len1,len2))>=0)&&digit>=k) {     
                    sub(x,y,len1,len2);              
                    z[len-j]++;  
                    len1=digit;
                    if(len1<len2&&y[len2-1]==0)        
                        len2=len1;                    
                }  
                if(temp<0){  
                    for(i=1;i<len2;i++)  
                        y[i-1]=y[i];  
                    y[i-1]=0;  
                    if(len1<len2)   
                        len2--;                                           
                }  
            }   
            for(i=len;i>0;i--) {  
                if(z[i])  
                    break;  
            } 
            //整数
            for(;i>=0;i--)  
                printf("%d",z[i]);  
            printf("\n");  
            //余数
            for(i=len1;i>0;i--){  
                if(x[i])  
                    break;  
            }  
            for(;i>=0;i--)  
                printf("%d",x[i]);  
            printf("\n");  
        }  
    }  
    return 0;  
}
