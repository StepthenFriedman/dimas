#include <stdio.h>

int isPal(char* a, char* b, int n){
    for (int i=0;i<n;i++) if (a[i]!=b[n-i-1]) return 0;
    return 1;
}

int findPal(char* start,char* end,int pal,int m){
    int max=pal,tmp=0;
    if (start==end&&!isPal(start, start, m)) return max;
    for (char *sp=start;sp<end;sp+=60){
        printf("start:%s\n",sp);
        for (char* ep=end-60;ep>=start;ep-=60){
            if (isPal(sp,ep , m)){
                printf("end:%s\n",ep);
                tmp=findPal(sp, ep, pal+1,m);
                max=max>tmp?max:tmp;
            }
        }
    }
    return max;
}

int main(){
    int n,m,i,max;
    char ipt[200][60];
    int palStart[200],palEnd[200];
    while (~scanf("%d%d",&n,&m)){
        for (i=0;i<n;i++) scanf("%s",&ipt[i]);
        printf("%d\n",findPal(&ipt[0], &ipt[n],0,m));
    }
    //
    return 0;
}