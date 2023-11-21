#include <stdio.h>

int max(int x,int y){
    return x>y?x:y;
}

//5 10 3 9
//3 9

//0 0 0 0 0 0 0 0 0 0 
//0 0 0 0 0 0 0 0 0 0 
//0 0 0 0 0 0 0 0 0 0 
//0 0 0 0 0 0 0 0 0 1 
//0 0 0 0 0 0 0 0 0 0 

int main(){
    int t,i,a,b,x,y,tmp1,tmp2;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d%d%d",&a,&b,&x,&y);
        tmp1=a*max(y,b-y-1);
        tmp2=b*max(x,a-x-1);
        printf("%d %d %d\n",tmp1,tmp2,max(tmp1,tmp2));
    }
    return 0;
}