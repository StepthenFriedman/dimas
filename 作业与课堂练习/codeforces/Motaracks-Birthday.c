#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int max(int x,int y,int z){
    x=x>y?x:y;
    x=x>z?x:z;
    return x;
}

int absub(int x,int y){
    return x>y?(x-y):(y-x);
}

int main(){
    int t,n,i,j,k,l,arr1[100000],arr2[100000],arr3[100000],maxdif,res,m,temp;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        for (maxdif=k=j=l=0;j<n;j++) scanf("%d",&arr1[j]);
        for (j=0;j<n;j++){
            if (arr1[j]==-1){
                if (j+1<n&&arr1[j+1]!=-1) arr2[k++]=arr1[j+1];
                if (j>0&&arr1[j-1]!=-1) arr2[k++]=arr1[j-1];
            }else{
                if ((~arr1[j-1])&&j>0){
                    temp=absub(arr1[j],arr1[j-1]);
                    maxdif=maxdif>temp?maxdif:temp;
                }
            }
        }
        if (!k){
            printf("0 1\n");goto end;
        }
        qsort(arr2,k,sizeof(int),cmp);
        for (j=0;j<k-1;j++){
            if (arr2[j]!=arr2[j+1]) {
                arr3[l++]=arr2[j];
            }
        }
        arr3[l++]=arr2[k-1];
        res=(arr3[0]+arr3[l-1])/2;
        printf("%d %d\n",max(res-arr3[0],arr3[l-1]-res,maxdif),res);
        end:;
    }
    return 0;
}