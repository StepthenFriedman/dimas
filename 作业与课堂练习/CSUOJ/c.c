#include <stdio.h>

int digit(long long x,int i){
    while (i){
        i--;x/=10;
    }
    return x%10;
}

int maxlen(long long x,long long y){
    long long m=x>y?x:y;
    int res=1;
    while (m){
        m/=10;res++;
    }
    return res;
}

int main(){
    long long x,y;
    int i,j;
	while (~scanf("%lld%lld",&x,&y)){
        int ml=maxlen(x, y),temp=0,res=0;
        for (i=0;i<ml;i++){
            if (digit(x,i)+digit(y,i)+temp>9){
                //printf("%d %d %d\n",digit(x,i),digit(y,i),temp);
                res++;temp=1;
            }else{
                temp=0;
            }
        }
        printf("%d\n",res);
    }
	return 0;
}