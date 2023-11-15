#include <stdio.h>

int main(){
    int a,b,c,d,e,f,x,y;
    while (~scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)){
        while (c>10){
            c-=10;b++;
        }
        while (b>10){
            b-=10;a++;
        }
        while (f>10){
            f-=10;e++;
        }
        while (e>10){
            e-=10;d++;
        }
        x=a*100+b*10+c;
        y=d*100+e*10+f;
        printf("%d\n",x/y);
    }
    
}