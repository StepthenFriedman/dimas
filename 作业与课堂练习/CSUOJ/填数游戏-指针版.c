#include <math.h>
#include<stdio.h>
#include<stdlib.h>

char temp[10]={0};
int k;
int **arr,*indx;

int isPrime(int a) {
    int sqt=sqrt((double)a);
	if (a<2)
		return 0;
	else if (a==2)
		return 1;
	else for (int i = 2; i < sqt+1; i++) if (!(a%i)) return 0;
	return 1;
}

int getk(int l){
    int x=sqrt((double)l);
    if (x*x<l) x++;
    return x*2+1;
}

void print(){
    int m=(k-1)/2,i,j,k,i1=0,i2=0,i3=0,i4=0;
    for (i=0;i<m;i++) {
        for (j=0;j<i;j++) printf("%5d",arr[1][i2++]);
        printf("    *");
        for (j=1;j<(m-i)*2;j++) printf("%5d",arr[0][i1++]);
        printf("    *");
        for (j=0;j<i;j++) printf("%5d",arr[2][i3++]);
        putchar('\n');
    }
    for (j=0;j<i;j++) printf("%5d",arr[1][i2++]);
    printf("    *");
    for (j=0;j<i;j++) printf("%5d",arr[2][i3++]);
    putchar('\n');
    for (i=m-1;i>-1;i--) {
        for (j=0;j<i;j++) printf("%5d",arr[1][i2++]);
        printf("    *");
        for (j=1;j<(m-i)*2;j++) printf("%5d",arr[3][i4++]);
        printf("    *");
        for (j=0;j<i;j++) printf("%5d",arr[2][i3++]);
        putchar('\n');
    }
    putchar('\n');
}

int judge(int x){
    if (isPrime(x)) return 0;
    int xclone=x,sum=0,tmp;
    while (xclone){
        sum+=xclone%10;
        xclone/=10;
    }
    if (isPrime(sum)) return 1;
    xclone=x;
    while (xclone){
        if (isPrime(xclone%10)) return 2;
        xclone/=10;
    }
    return 3;
}
int main(){
    int i,j,m,t,max,x;
    char *end,*p,*f;
    f=p=(char*)malloc(100001*sizeof(char));
    arr=(int**)malloc(sizeof(int*)*4);
    while(~scanf("%s%d", p, &m)){
        if (m==0) break;
        for (end=p;*end!='\0';end++);
        indx=(int*)calloc(4,sizeof(int));
        for (i=0;i<4;i++) arr[i]=(int*)calloc(10000,sizeof(int));
        while (p<end){
            snprintf(temp,m+1,"%s",p);
            sscanf(temp,"%d",&x);
            t=judge(x);
            arr[t][indx[t]++]=x;
            p+=m;
        }
        max=indx[0];
        for (i=1;i<4;i++) if (max<indx[i]) max=indx[i];
        k=getk(max);
        print();
        for (i=0;i<4;i++) free(arr[i]);
        free(indx);
	}
    free(arr);
    free(f);
    return 0;
}
