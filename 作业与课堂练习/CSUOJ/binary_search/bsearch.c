#include <stdio.h>
#include <stdlib.h>

void* max_aviliable(void *start,unsigned long total_elem,unsigned long size,int (*check)(const void *)){
    void *end=start+(total_elem)*size,*mid=start+(total_elem/2)*size;
    while (start+size<end){
        if (check(mid)) start=mid;
        else end=mid;
        mid=start+((end-start)/(size*2))*size;
    }
    return start;
}

int check(const void *x){
    return *((int*)x)>0;
}

int check_find_certain(const void *x){
    return *((int*)x)<=8;
}

int main(){
    //find the maximum aviliable 
    char a[]={1,2,3,4,5,6,7,0,0,0,0};
    printf("%d\n",*((char*)max_aviliable(a,11,sizeof(char),check)));

    //find a certain value in a sorted array
    int b[]={1,2,3,4,5,6,6,7,9,10,11,12};
    printf("%d\n",*((int*)max_aviliable(b,11,sizeof(int),check_find_certain)));
    return 0;
}