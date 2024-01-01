#include <stdio.h>
void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void quicksort_double(void *start,void *start2,void *end,void *end2,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    void *base=start,*i=start,*j=end,
        *base2=start2,*i2=start2,*j2=end2;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size,j2-=size;
        while (cmp(i,base)<=0&&i<j) i+=size,i2+=size;
        swap(i,j,size);
        swap(i2,j2,size);
    }
    swap(base,j,size);
    swap(base2,j2,size);
    quicksort_double(start,start2,j-size,j2-size,size,cmp);
    quicksort_double(j+size,j2+size,end,end2,size,cmp);
}
void qsortd(void *start,void *start2,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort_double(start,start2,start+(total_elem-1)*size,start2+(total_elem-1)*size,size,cmp);
}

int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}
int main(){
    int a[10]={2,3,5,1,7,8,10,2,4,6},
        b[10]={3,4,6,2,8,9,11,3,5,7},
    i;
    qsortd(a,b,10,sizeof(int),cmp);
    for (i=0;i<10;i++) printf("(%d,%d) ",a[i],b[i]);
}