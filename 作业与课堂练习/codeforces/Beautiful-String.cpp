#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

int main(){
    long long int t,n,i,j,k,x,y;
    scanf("%lld",&t);
    for (i=0;i<t;i++){
        scanf("%lld%lld",&n,&k);
        for (j=1;j*(j-1)/2<k;j++);
        x=n-2-j;y=n-(k-(j*(j+1)/2));
        std::string s(n, 'a');
        s[x]=s[y]='b';
        std::cout<<s<<'\n';
    }
    return 0;
}
