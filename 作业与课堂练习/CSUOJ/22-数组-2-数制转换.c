/*
小南学了进制转换后，想编写一个正整数m的任意n进制转换为p进制正整数t的程序。其中m为不超过int类型的正整数，转换后的p进制正整数t不超过20位，n,p均为2-10之间的正整数。 
程序的输入形式为：m<n>p，表示把n进制的整数m转换为p进制输出，输出形式为： m<n>=t<p>。
例如：输入为：48<10>8
          输出结果为：48<10>=60<8> 
说明：48<10>8表示将10进制数48，转换成8进制数输出，转换后的8进制数为60。

多组样例。每个测试样例输入一行字符串，形式如m<n>p

对于每组样例，输出数制转换后的结果，形式如 m<n>=t<p>，具体格式见样例输出。每个输出占一行。

48<10>8
44<7>8

48<10>=60<8>
44<7>=40<8>
*/
#include <stdio.h>

unsigned long long to_digital(unsigned long long x,int radix){
    if (radix==10) return x;
    unsigned long long res=0,plus=1;
    while (x) res+=plus*(x%10),plus*=radix,x/=10;
    return res;
}
unsigned long long digital_to(unsigned long long x,int radix){
    if (radix==10) return x;
    unsigned long long res=0,plus=1;
    while (x) res+=plus*(x%radix),plus*=10,x/=radix;
    return res;
}
unsigned long long convert(unsigned long long x,int radix1,int radix2){
    unsigned long long res=0,plus=1;
    while (x) res+=plus*(x%radix2),plus*=radix1,x/=radix2;
    return res;
}

int main(){
    unsigned long long m;int n,p;unsigned long long dbg;
    while (~scanf("%llu<%d>%d",&m,&n,&p)) {
        printf("%llu<%d>=%llu<%d>\n",m,n,convert(m,n,p),p);
    }
}