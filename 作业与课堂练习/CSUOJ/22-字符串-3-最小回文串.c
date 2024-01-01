#include <stdio.h>
#include <string.h>

void add1(char *num){
    int len=strlen(num);
    int start=len-1;
    num[start]++;
    next:
    if (num[start]>'9'){
        num[start]-=10;
        num[start-1]++;
        start--;
        goto next;
    }
}

int main(){
	char ipt[10010],part[10000];
    int len,i,cmp,start;
	while (~scanf("%s",&ipt)){
		len=strlen(ipt);
        for (i=0;i<len;i++){
            if (ipt[i]!='9') goto next;
        }
        putchar('1');for (i=1;i<len;i++) putchar('0');putchar('1');putchar('\n');continue;
        next:
        cmp=-1;
        for (i=1;i<=len/2;i++){
            if (ipt[(len/2)-i]<ipt[((len-1)/2)+i]) break;
            else if (ipt[(len/2)-i]>ipt[((len-1)/2)+i]) {cmp=1;goto then;}
        }
        then:
        if (cmp>0) {
            printf("%.*s",(len/2),ipt);
            if (len%2) putchar(ipt[len/2]);
            for (i=(len/2)-1;i>-1;i--) putchar(ipt[i]);
            putchar('\n');
        }
        else {
            strncpy(&part[1],ipt,((len-1)/2)+1);
            part[0]='0';
            part[((len-1)/2)+2]='\0';
            add1(part);
            printf("%s",part+(part[0]=='0'));
            for (i=strlen(part)-1-(len%2);i>(part[0]=='0')-1;i--) putchar(part[i]);
            putchar('\n');
        }
	}
	return 0;
}
