#include <stdio.h>

int main(){
    char ipt[10000],reduce[10000];
    int i,m,n;
    while(printf("enter a message:"),fgets(ipt,10000,stdin)!=NULL){
        printf("enter m,n:");
        scanf("%d,%d",&m,&n);
        for (i=0;i<n;i++) reduce[i]=ipt[m+i];
        reduce[i]='\0';
        printf("result:%s\n",reduce);
    }
}