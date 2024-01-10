#include <stdio.h>
#include <stdlib.h>

int* get_max_array(int *start,unsigned long total_elem,unsigned long window_elem){
    int *end=start+total_elem,
        **window=(int**)malloc(total_elem*sizeof(int*)),
        **head=window,**toe=window+1,
        *result=(int*)malloc(total_elem*sizeof(int)),
        *reshead=result;
    
    *head=start++;
    *(reshead++)=**head;
    for (;start<end;start++){
        while (toe>head && (*start)>=(**(toe-1))) toe--;
        *(toe++)=start;
        while ((start-(*head))>=window_elem) head++;
        *(reshead++)=**head;
    }
    free(window);
    return result;
}

int* get_min_array(int *start,unsigned long total_elem,unsigned long window_elem){
    int *end=start+total_elem,
        **window=(int**)malloc(total_elem*sizeof(int*)),
        **head=window,**toe=window+1,
        *result=(int*)malloc(total_elem*sizeof(int)),
        *reshead=result;
    
    *head=start++;
    *(reshead++)=**head;
    for (;start<end;start++){
        while (toe>head && (*start)<=(**(toe-1))) toe--;
        *(toe++)=start;
        while ((start-(*head))>=window_elem) head++;
        *(reshead++)=**head;
    }
    free(window);
    return result;
}

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

int cmp(const void* x,const void* y){
    return *((int*)x)-*((int*)y);
}

void get_array(void *start,void *result,unsigned long total_elem,unsigned long window_elem,unsigned long size,int (*cmp)(const void*,const void*)){
    void *end=start+total_elem*size,
        **window=(void**)malloc(total_elem*sizeof(void*)),
        **head=window,**toe=window+1,
        *reshead=result;
    
    *head=start;
    copy(reshead,start,size);
    start+=size,reshead+=size;
    for (;start<end;start+=size){
        while (toe>head && cmp(start,*(toe-1))>=0) toe--;
        *(toe++)=start;
        while ((start-(*head))>=window_elem*size) head++;
        copy(reshead,*head,size);
        reshead+=size;
    }
    free(window);
}

void get_array_skip(void *start,void *result,unsigned long total_elem,unsigned long window_elem,unsigned long size,unsigned long skip_elem,int (*cmp)(const void*,const void*)){
    void *end=start+total_elem*size,
        **window=(void**)malloc(total_elem*sizeof(void*)),
        **head=window,**toe=window+1,
        *reshead=result;
    
    *head=start;
    copy(reshead,start,size);
    start+=size*skip_elem,reshead+=size*skip_elem;
    for (;start<end;start+=size*skip_elem){
        while (toe>head && cmp(start,*(toe-1))>=0) toe--;
        *(toe++)=start;
        while ((start-(*head))>=window_elem*size) head++;
        copy(reshead,*head,size);
        reshead+=size*skip_elem;
    }
    free(window);
}

int main(){
    int arr[10]={2,5,4,1,3,2,6,3,5,4},i;
    int *res=get_max_array(arr,10,3);
    for (i=0;i<10;i++) printf("%d ",res[i]),res[i]=0;
    printf("\n%lu,%lu,%lu,%lu,%lu\n",sizeof(int*),sizeof(long long*),sizeof(short*),sizeof(char*),sizeof(void*));

    get_array(arr,res,10,3,sizeof(int)*2,cmp);
    for (i=0;i<10;i++) printf("%d ",res[i]),res[i]=0; putchar('\n');

    get_array_skip(arr,res,10,3,sizeof(int),2,cmp);
    for (i=0;i<10;i++) printf("%d ",res[i]); putchar('\n');

    free(res);
    return 0;
}