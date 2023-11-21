#include <stdio.h>

int main(){
    int t,i,a,b,c,res;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        res=0;
        scanf("%d%d%d",&a,&b,&c);
        if (a){a--;res++;}
        if (b){b--;res++;}
        if (c){c--;res++;}
        if (a>=b&&a>=c){    
            if (a&&b){a--;b--;res++;}
            if (a&&c){a--;c--;res++;}
            if (b&&c){b--;c--;res++;}
        }
        else if (b>=a&&b>=c) {
            if (b&&c){b--;c--;res++;}
            if (a&&b){a--;b--;res++;}
            if (a&&c){a--;c--;res++;}
        }else {
            if (b&&c){b--;c--;res++;}
            if (a&&c){a--;c--;res++;}
            if (a&&b){a--;b--;res++;}
        }
        if (a&&b&&c){res++;}
        printf("%d\n",res);
    }
    return 0;
}