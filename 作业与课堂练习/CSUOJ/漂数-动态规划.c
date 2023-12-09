#include <stdio.h>
int min(int a,int b,int c,int d){
	int min;
	min=a<b?a:b;
	min=min<c?min:c;
	min=min<d?min:d;
	return min;
}//判断分别乘于2，3，5，7后数的大小进行排序 
int main(){

    int i=1,j=1,k=1,n,p[6000],m=1;
    p[1]=1;
    for(n=2;n<=5842;n++){
        p[n]=min(p[i]*2, p[j]*3, p[k]*5, p[m]*7);
        if(p[n]==p[i]*2) i++;
        if(p[n]==p[j]*3) j++;
        if(p[n]==p[k]*5) k++;
        if(p[n]==p[m]*7) m++;
    //树形结构 
    }

    while(scanf("%d",&m)!=EOF&&m){
        int mod=m%100;
    //对m不同情况下结尾字母进行区分 
        if(mod==12||mod==11||mod==13)printf("The %dth humble number is %d.\n",m,p[m]);
        else {
            switch(m%10){
                case(1):printf("The %dst humble number is %d.\n",m,p[m]);break;
                case(2):printf("The %dnd humble number is %d.\n",m,p[m]);break;
                case(3):printf("The %drd humble number is %d.\n",m,p[m]);break;
                default :printf("The %dth humble number is %d.\n",m,p[m]);
            }
        }
	}
    return 0;
}