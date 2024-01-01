#include <stdio.h>
#include <string.h>

int a[2010],dul[2010],num[2010];

int main(){
    int t,n,i,j,max,temp,ipt,len;
    scanf("%d",&t);
    while (t--){
        max=0,temp=-1;
        scanf("%d",&n);
        memset(dul,0,n*sizeof(int));
        memset(num,0,n*sizeof(int));
        for (j=-1,i=0;i<n;i++) {
            scanf("%d",&ipt);
            if (ipt==temp) dul[j]++;
            else temp=ipt,num[++j]=ipt;
        }
        len=j+1;
        for (i=0;i<len;i++){
            
        }
    }
    return 0;
}