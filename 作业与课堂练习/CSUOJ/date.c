#include <stdio.h>

int isGoodYear(int i){
    return (i%4==0&&i%100!=0)||i%400==0;
}

int getday(int m,int y){
    if (m==2) return 28+isGoodYear(y);
    return (m>7^m%2)+30;
}

int main(){
    int i;
    for (i=1;i<=12;i++){
        printf("%d ",getday(i,2000));
    }
}
