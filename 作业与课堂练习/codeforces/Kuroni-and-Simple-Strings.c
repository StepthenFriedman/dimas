#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
    int i,j,k,l;
    char ipt[2000];
    int res[2000];
    while (~scanf("%s",&ipt)){
        for (i=0;ipt[i]!='\0';i++);
        j=-1;k=i;l=0;
        while ((j<i)&&(k)&&(j<k)){
            while (ipt[++j]==')');
            while (ipt[--k]=='(');
            res[l++]=j+1;res[l++]=k+1;
        }
        qsort(res,l-2,sizeof(int),cmp);
        if (!(l-2)) printf("0\n");
        else {
            printf("1\n%d\n",l-2);
            for (i=0;i<l-2;i++) printf("%d ",res[i]);
            putchar('\n');
        }
    }
    return 0;
}