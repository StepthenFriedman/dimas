#include <stdio.h>
int v1,v2,t,s,l,l1,l2,rest,t;
int main(){
    
    while (scanf("%d %d %d %d %d",&v1,&v2,&t,&s,&l)!=EOF){
        rest=l1=l2=0;t=0;
        while (1){
            if ((l1-l2>=t)&&!rest) rest=s;
            if (!rest) l1+=v1; else rest--;
            l2+=v2;t++;
            if (l1>=l&&l2>=l){
                printf("D\n%d\n",t);
                break;
            }else if (l1>=l){
                printf("R\n%d\n",t);
                break;
            }else if (l2>=l){
                printf("T\n%d\n",t);
                break;
            }
            printf("now:rabbit:%d,turttle:%d\n",l1,l2);
        }
    }
    return 0;
}

