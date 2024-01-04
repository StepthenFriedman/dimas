#include<stdio.h>
#include<string.h>

int arr[400][400];
int main(){
    int n,i,j,k,num;
    while (~scanf("%d",&n)){
        memset(arr,0,n*n*sizeof(int));
        for (i=j=-1,num=1,k=0;k<((2*n)-1);k++) switch (k%4){
            case 0:for (i++,j++;j<n-(k/4);j++) arr[i][j]=num++;continue;
            case 1:for (i++,j--;i<n-(k/4);i++) arr[i][j]=num++;continue;
            case 2:for (i--,j--;j>=(k/4);j--) arr[i][j]=num++;continue;
            case 3:for (i--,j++;i>(k/4);i--) arr[i][j]=num++;
        }
        for (i=0;i<n;i++) {for (j=0;j<n;j++) printf("%2d ",arr[i][j]);putchar('\n');}
    }
    return 0;
}
