#include <stdio.h>

int main(){
    int n,i,j,k1,k2,arr[9],arr1[9],arr2[9];
    while (~scanf("%d",&n)){
        for (i=0;i<n;i++){
            for (j=0;j<9;j++) scanf("%d",&arr[j]);
            k1=k2=0;
            for (j=8;j>0;j--) {if (arr[j]<arr[0]) arr1[k1++]=arr[j]; if (arr[9-j]>arr[0]) arr2[k2++]=arr[9-j];}
            for (j=0;j<k1;j++) printf("%d ",arr1[j]);
            printf("%d ",arr[0]);
            for (j=0;j<k2;j++) printf("%d ",arr2[j]);
            putchar('\n');
        }
    }
    
}