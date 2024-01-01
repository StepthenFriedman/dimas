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
long long list[10000];
int main(){
    char temp[1000],ipt; long long value; int i=0,n=0;
    next:
    ipt=getchar();
    if (ipt==EOF) {
        if (i){
            temp[i]='\0';
            sscanf(temp,"%lld",&list[n++]);
        }
        qsort(list,n,sizeof(long long),cmp);
        for (i=0;i<n;i++) printf("%lld ",list[i]);
        putchar('\n');
        return 0;
    }
    else if (ipt=='\n'){
        if (i){
            temp[i]='\0';
            sscanf(temp,"%lld",&list[n++]);
        }
        qsort(list,n,sizeof(long long),cmp);
        for (i=0;i<n;i++) printf("%lld ",list[i]);
        putchar('\n');
        i=n=0;
        goto next;
    }
    else if (ipt=='5'){
        if (i){
            temp[i]='\0';
            sscanf(temp,"%lld",&list[n++]);
        }
        i=0;
        goto next;
    }
    else {
        temp[i++]=ipt;
        goto next;
    }
    return 0;
}