#include <stdio.h>

int main(){
    int t,n,i,j,len,a,b,p;
    char road[200000];
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d%d%s",&a,&b,&p,&road);
        for (len=0;road[len]!='\0';len++);
        j=len-1;
        while (j>0&&p>0){
            if (road[j-1]=='A'){
                if (p>=a){
                    p-=a;
                    while (j>-1&&road[j-1]=='A') j--;continue;
                }
            }
            else if (road[j-1]=='B'){
                if (p>=b){
                    p-=b;
                    while (j>-1&&road[j-1]=='B') j--;continue;
                }
            }
            break;
        }
        printf("%d\n",j+1);
    }
    return 0;
}