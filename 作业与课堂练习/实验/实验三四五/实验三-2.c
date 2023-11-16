#include <stdio.h>

float abs(double x){
    return x>0?x:-x;
}

int main(){
    double x,y,tmp;
    while ((printf("Enter a positive number: "),y=1,~scanf("%lf",&x))){
        while (1){
            tmp=((x/y)+y)/2.;
            if (abs(tmp-y)<0.00001*y) break;
            else y=tmp;
        }
        printf("%g\n",y);
    }
    
    return 0;
}