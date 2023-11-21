#include <stdio.h>

int max(int x,int y){
    return x>y?x:y;
}
int main(){
    int t,i,a,b,x,y,tmp1,tmp2;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d%d%d",&a,&b,&x,&y);
        printf("%d\n",max(a*max(y,b-y-1),b*max(x,a-x-1)));
    }
    return 0;
}