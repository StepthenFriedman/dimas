#include <stdio.h>
#include <stdlib.h>
#define E9 1000000000LL
#define LEN 9
unsigned long long* init(unsigned long long x,unsigned long digits){
    unsigned long long *res=(unsigned long long *)malloc(digits*sizeof(unsigned long long));
    res[digits-1]=x;
    return res;
}

unsigned long getnum(unsigned long long* ipt){
    char s[1000];unsigned long i,digits,head;
    *ipt=0;
    unsigned long long* x=ipt+1;
    scanf("%s",&s);
    for (i=0;s[i]!='\0';i++);
    digits=i/9,head=i%9;
    char *p=&s[0];
    if (head){
        char temp[head+1];
        snprintf(temp,head+1,"%s",s);
        sscanf(temp,"%llu",&x[0]);
        p+=head;
    }
    head=!!head;
    for (i=head;i<digits+head;i++){
        sscanf(p,"%9llu",&x[i]);
        p+=9;
    }
    return digits+head+1;
}

void display(unsigned long long* x,int digits){
    int i=0;
    while (!x[i]) i++;
    printf("%llu",x[i++]);
    for (;i<digits;i++) printf("%09llu",x[i]);
}

void debug(unsigned long long* x,int digits){
    for (int i=0;i<digits;i++) printf("%llu ",x[i]);
    printf("\ndigits:%d\n",digits);
}

void add(unsigned long long * x,unsigned long digits,long long y){
    long start=digits-1;
    if (E9<=y+x[start]) x[start]=(long long)(y-E9)+x[start];
    else {x[start]+=y;return;}
    while (start){    
        start--;
        if (E9<=x[start]+1) {
            x[start]=(x[start]+1)-E9;
        }else {x[start]++;return;}
    }
}

void addnum(unsigned long long * x,unsigned long x_digits,unsigned long long *y,unsigned long y_digits){
    long start=1,enter=0;
    long long temp=0;
    while (start<=x_digits){
        temp=x[x_digits-start]+y[y_digits-start]+enter;
        enter=0;
        if (E9<=temp) {
            x[x_digits-start]=temp-E9,enter=1;
        }else x[x_digits-start]=temp;
        start++;
    }
}
/*
void * plusnum(unsigned long long * x,unsigned long x_digits,unsigned long long *y,unsigned long y_digits){
    for (i=0;!y[i];i++);
    if (i==y_digits-1) {
        plus(x,digits,y[i]);
        return;
    }
    unsigned long long c=divide(y,y_digits,E9);
}
*/
void plus(unsigned long long *x,unsigned long digits,unsigned long y){
    long start=digits-1;
    unsigned long long res,enter=0;
    while (start>=0){
        res=x[start]*y+enter;
        enter=0;
        while (res>=E9){
            res-=E9;enter++;
        }
        x[start]=res;
        start--;
    }
}

unsigned long long * newplus(unsigned long long *x,unsigned long digits,unsigned long y){
    unsigned long long *new=(unsigned long long *)malloc((digits+1)*sizeof(unsigned long long));
    *new=0;
    long start=digits-1;
    unsigned long long res,enter=0;
    while (start>=0){
        res=x[start]*y+enter;
        enter=0;
        while (res>=E9){
            res-=E9;enter++;
        }
        new[start+1]=res;
        start--;
    }
    return new;
}

unsigned long long* move(unsigned long long *x,unsigned long * digits,unsigned long move_digits){
    unsigned long long *new=(unsigned long long *)malloc(((*digits)+move_digits)*sizeof(unsigned long long));
    unsigned int i;
    for (i=0;i<move_digits;i++) new[i]=0;
    for (i=0;i<(*digits);i++) new[i+move_digits]=x[i];
    free(x);
    *digits+=move_digits;
    return new;
}


unsigned long long divide(unsigned long long * x,unsigned long digits,unsigned long long y){
    unsigned long start=0;
    unsigned long long enter=0;
    while (start<digits){
        x[start]+=enter*E9;
        enter=x[start]%y;
        x[start++]/=y;
    }
    return enter;
}

unsigned long long * newdivide(unsigned long long * x,unsigned long digits,unsigned long long *rem,unsigned long long y){
    unsigned long long *new=(unsigned long long *)malloc(digits*sizeof(unsigned long long));
    unsigned long start=0;
    unsigned long long enter=0;
    while (start<digits){
        new[start]=x[start];
        new[start]+=enter*E9;
        enter=new[start]%y;
        new[start++]/=y;
    }
    *rem=enter;
    return new;
}

void sub(unsigned long long * x,unsigned long digits,long long y){
    unsigned long start=digits-1;

    if (x[start]<=y) x[start]=(E9+x[start])-y;
    else {x[start]-=y;return;}
    next:
    start--;
    if (x[start]<1) {
        x[start]=E9-1;
        goto next;
    }else x[start]--;
}

void test1(){
    unsigned long long i,digits=100,*x=init (1,digits);
    for (i=1;i<=100;i++) plus(x,digits,i);
    display(x,digits);putchar('\n');
    debug(x,digits);
}
//100!=93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
void test2(){
    unsigned long long *x=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    unsigned long digit=getnum(x);
    add(x,digit,1);
    display(x,digit);putchar('\n');
}

void test3(){
    unsigned long long i,digits=100,*x=init (1,digits);
    for (i=1;i<=100;i++) plus(x,digits,i);
    for (i=1;i<=100;i++) divide(x,digits,i);
    display(x,digits);putchar('\n');
}

void test4(){
    unsigned long long i,digits=300,*x=init (1,digits);
    for (i=1;i<=1000;i++) plus(x,digits,i);
    display(x,digits);putchar('\n');
}

void test5(){
    unsigned long long *x=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    unsigned long xdigit=getnum(x);
    unsigned long long *y=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    unsigned long ydigit=getnum(y);
    addnum(x,xdigit,y,ydigit);
    display(x,xdigit);putchar('\n');
}

void test6(){
    unsigned long long *x=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    unsigned long xdigit=getnum(x);
    unsigned long long *new=newplus(x,xdigit,999999999);
    display(new,xdigit+1);putchar('\n');
}
/*
void test7(){
    unsigned long long *x=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    unsigned long xdigit=getnum(x);
    unsigned long long *y=(unsigned long long *)malloc(100*sizeof(unsigned long long));
    unsigned long ydigit=getnum(y);
    plusnum(x,xdigit,y,ydigit);
    display(x,xdigit);putchar('\n');
}
*/
int main(){
    test6();
    return 0;
}