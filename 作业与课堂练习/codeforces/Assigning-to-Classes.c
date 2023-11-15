#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
    int t,n,i,j,stu[200000];
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        for (j=0;j<n*2;j++) scanf("%d",&stu[j]);
        qsort(stu,2*n,sizeof(int),cmp);
        printf("%d\n",stu[n]-stu[(n)-1]);
    }

    return 0;
}
