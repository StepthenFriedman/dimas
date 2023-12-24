#include<stdio.h>
#include<string.h>

int isPal(char* ipt,int st,int end){
    for (int i=0;i<(end-st)/2;i++) if (ipt[st+i]!=ipt[end-1-i]) return 0;
    return 1;
}

int findPal(char* ipt,int st,int len){
    for (int i=len-1;i>st;i--) if (ipt[i]==ipt[st]&&isPal(ipt,st,i+1)) return i-st+1;
    return 0;
}

int main(){
    int len,i,max,tmp;
	char a[1001];
	while(scanf("%s",&a)!=EOF){
		len=strlen(a),max=1;
        for (i=0;i<len;i++){
            tmp=findPal(a,i,len);
            if (max<tmp) max=tmp;
        }
        printf("%d\n",max);
	}
	return 0;
}