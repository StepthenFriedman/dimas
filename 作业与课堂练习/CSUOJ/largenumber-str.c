#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){return a>b?a:b;}

char* addstr(char*a,char*b){
    int lenA,lenB,lenC,i=1,carry=0;
    int temp;
    for (lenA=0;a[lenA]!='\0';lenA++);
    for (lenB=0;b[lenB]!='\0';lenB++);
    lenC=max(lenA,lenB)+1;
    char*c=(char*)malloc(lenC);
    c[lenC]='\0';

    while (i<=lenA&&i<=lenB){
        temp=a[lenA-i]-'0'+b[lenB-i]+carry;
        carry=0;
        if (temp>'9') temp-=10,carry=1;
        c[lenC-i]=temp;
        i++;
    }
    if (lenA>lenB) while (i<=lenA) {
        temp=a[lenA-i]+carry;
        carry=0;
        if (temp>'9') temp-=10,carry=1;
        c[lenC-i]=temp;
        i++;
    }
    else if (lenA<lenB) while (i<=lenB) {
        temp=b[lenB-i]+carry;
        carry=0;
        if (temp>'9') temp-=10,carry=1;
        c[lenC-i]=temp;
        i++;
    }
    if (carry) {c[0]='1';return c;}
    else return c+1;
}

int main(){
    char ipt1[10000],ipt2[10000];
    while (~scanf("%s%s",ipt1,ipt2)){
        printf("%s + %s = %s\n",ipt1,ipt2,addstr(ipt1,ipt2));
    }
    return 0;
}