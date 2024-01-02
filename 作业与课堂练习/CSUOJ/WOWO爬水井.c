#include <stdio.h>

int main(){
    long h,u,d,f,g;
    while((~scanf("%ld%ld%ld%ld",&h,&u,&d,&f))&&(h+u+d+f)){
        int i=1; f*=u;h*=100;g=h;u*=100;d*=100;      
        while(1){
            h-=u;
         	if(h<0){printf("success on day %d\n",i);break;}
            u-=f;
            if(u<=0) u=0;
            h+=d;
            if(h>g){printf("failure on day %d\n",i);break;}
            i++;
        }
    }
    return 0;
}
