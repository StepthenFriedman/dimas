#include <stdio.h>
void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
    void *base=start,*i=start,*j=end-size;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort(start,j,size,cmp);
    quicksort(j+size,end,size,cmp);
}
void qsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+total_elem*size,size,cmp);
}

int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}
int main(){
    int a[10]={2,3,5,1,7,8,10,2,4,6},i;
    qsort(a,10,sizeof(int),cmp);
    for (i=0;i<10;i++) printf("%d ",a[i]);
}