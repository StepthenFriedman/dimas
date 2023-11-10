#include <stdio.h>
int max(int *rep){
    int res=0;
    for (int i=1;i<4;i++) res=(rep[res]<rep[i])?i:res;
    return res;
}

char acgt[5]={'A','C','G','T','\0'};
int main(){
    int t,m,n,i,j,k,repeat[4]={0,0,5,0},rpt;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        rpt=0;
        scanf("%d %d",&m,&n);
        char ipt[m][n+1],res[n+1];
        for (j=0;j<m;j++) scanf("%s",&ipt[j]);
        for (j=0;j<n;j++){
            repeat[0]=repeat[1]=repeat[2]=repeat[3]=0;
            for (k=0;k<m;k++){
                switch (ipt[k][j]){
                case 'A': repeat[0]++; continue;
                case 'C': repeat[1]++; continue;
                case 'G': repeat[2]++; continue;
                case 'T': repeat[3]++; continue;
                }
            }
            for (k=0;k<4;k++) if (k!=max(repeat)) rpt+=repeat[k];
            res[j]=acgt[max(repeat)];
        }
        res[n]='\0';
        printf("%s\n%d\n",res,rpt);
    }
    return 0;
}