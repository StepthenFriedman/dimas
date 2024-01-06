#include <stdio.h>
#include <stdlib.h>
long long arr[100000];

void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    void *base=start,*i=start,*j=end;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort(start,j-size,size,cmp);
    quicksort(j+size,end,size,cmp);
}
void qsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+(total_elem-1)*size,size,cmp);
}

int cmp(const void * a,const void * b){
    return *(long long*)a-*(long long*)b;
}

int main(){
    int n,i;
    long long sum;
    while (~scanf("%d",&n)){
        for (i=0;i<n;i++) scanf("%d",&arr[i]);
        qsort(arr,n,sizeof(long long),cmp);
        for (sum=i=0;i<n;i++){
            if (sum>=arr[i]){
                printf("No\n");goto end;
            }
            sum+=arr[i];
        }
        printf("Yes\n");
        end:;
    }
    return 0;
}