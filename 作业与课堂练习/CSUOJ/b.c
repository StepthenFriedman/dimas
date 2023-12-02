#include <stdio.h>

int main(){
    int x,y;char m,n;
	while (~scanf("%2d:%2d%c%c",&x,&y,&m,&n)){
        if ((m=='A')||(m=='a')){
            if (x==12) x-=12;
        }
        else {
            if (x!=12) x+=12;
        }
        printf("%02d:%02d\n",x,y);
    }
	return 0;
}