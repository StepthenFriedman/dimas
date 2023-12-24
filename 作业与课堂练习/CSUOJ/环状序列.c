#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ipt[1010],s[1010];
int arr[1010];

int main() {
    int T,i,j,len,min;
    char mins[1010];
    scanf("%d",&T);
    while (T--){
        min=130;mins[0]='\0';
        scanf("%s",&ipt);
        len=strlen(ipt);
        for (i=0;i<len;i++) if (ipt[i]<min) min=ipt[i];
        for (i=0;i<len;i++) if (ipt[i]==min) {
            strcpy(s,&ipt[i]);
            snprintf(&s[len-i],i+1,"%s",ipt);
            if (mins[0]=='\0'||strcmp(mins,s)>0) strcpy(mins,s);
        }
        printf("%s\n",mins);
    }

}