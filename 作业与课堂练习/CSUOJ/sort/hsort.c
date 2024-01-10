#include <stdio.h>
//             2^0
//      2^1          2^1+1
//  2^2    2^2+1  2^2+2    2^2+3 

//             2^0-1
//      2^1-1          2^1
//  2^2-1    2^2  2^2+1    2^2+2 

void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}


void heapify(void *start,unsigned long father,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    start-=size;
    unsigned long this,next;
    for (this=father,next=this*2;next<=total_elem;this=next,next*=2){
        if (next+1<=total_elem && cmp(start+size*next,start+size*(next+1))<0) next++;
        if (cmp(start+size*this,start+size*next)<0) swap(start+size*this,start+size*next,size);
        else break;
    }
}

void hsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start+(total_elem-1)*size;
    unsigned long ptr;
    for (ptr=(total_elem)/2;ptr>0;ptr--) heapify(start,ptr,total_elem,size,cmp);
    for (;sorted>start;sorted-=size){
        swap(sorted,start,size);
        heapify(start,1,--total_elem,size,cmp);
    }
}

int main(){
    int a[]={10,8,2,3,7,1,0,4,7,2,9,7,6,5,8,4},i,len=sizeof(a)/sizeof(int);
    hsort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]);
}