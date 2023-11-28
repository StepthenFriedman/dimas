#include <stdio.h>
char res[100000],ipt;
int main(){
    int i=0,EOS=0;
    while (~(ipt=getchar())) if (ipt=='\n'||(EOS=0)||(res[i++]=ipt,0)) for (i--;(EOS||!(i+=(EOS=1)))&&(i>-1||(putchar('\n'),i=EOS=0));i--) putchar(res[i]); 
}