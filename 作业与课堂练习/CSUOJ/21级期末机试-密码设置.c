#include<stdio.h>
#include<string.h>

int main()
{
	char s[100000];
    int i,len,num,big,small,special;
	while(scanf("%s", &s)!=EOF){
		len=strlen(s);
        num=big=small=special=0;
        if (len<8) {printf("no\n");continue;}
        for (i=0;i<len;i++){
            if (s[i]>='0'&&s[i]<='9') num=1;
            else if (s[i]>='A'&&s[i]<='Z') big=1;
            else if (s[i]>='a'&&s[i]<='z') small=1;
            else if (s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='*'||s[i]=='~') special=1;
        }
        if ((num+big+small+special)>=3) printf("yes\n");
        else printf("no\n");
	}
	return 0;
}
