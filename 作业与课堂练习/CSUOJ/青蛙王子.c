#include <stdio.h>
int judge(int a, int b, int c){
    if (a==c||b==c) return 1;
    if (!(a+b)) return 0;
    if (!a) return !(c%b);
    else if (!b) return !(c%a);
    if (c>a) return judge(b,a,c%a);
    else if (b>a) return judge(b%a,a,c);
    else return judge(a%b,b,c);
}

int main(){
	int a,b,c;
    while (~scanf("%d%d%d",&a,&b,&c)){
        if (judge(a,b,c)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
