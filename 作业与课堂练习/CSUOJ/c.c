#include <stdio.h>
#include <stdlib.h>
typedef struct time{
    int start1,start2,end1,end2;
    char start,end;
}time;

int main(){
    int s1,s2,s,min,tempVal,indx,i;
    time list[10],temp;
    while(printf("enter a 24-hour time:"),~scanf("%d:%d",&s1,&s2)){
        s=s1*60+s2;
        time temp1={8,0,10,16,'a','a'};
        list[0]=temp1;
        time temp2={9,43,11,52,'a','a'};
        list[1]=temp2;
        time temp3={11,19,1,31,'a','p'};
        list[2]=temp3;
        time temp4={12,47,3,0,'p','p'};
        list[3]=temp4;
        time temp5={2,0,4,8,'p','p'};
        list[4]=temp5;
        time temp6={3,45,5,55,'p','p'};
        list[5]=temp6;
        time temp7={7,0,9,20,'p','p'};
        list[6]=temp7;
        time temp8={9,45,11,58,'p','p'};
        list[7]=temp8;

        min=1000000;indx=0;
        for (i=0;i<8;i++){
            temp=list[i];
            tempVal=abs((temp.start1+((temp.start=='p')*12)*60)+temp.start2-s);
            if (min>tempVal) min=tempVal,indx=i;
        }
        temp=list[indx];
        printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",temp.start1,temp.start2,temp.start,temp.end1,temp.end2,temp.end);
    }
}