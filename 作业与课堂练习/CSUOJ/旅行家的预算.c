#include <stdio.h>

double min(double i,double j){
    return i<j?i:j;
}

double max(double i,double j){
    return i>j?i:j;
}

void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    void *base=start,*i=start,*j=end;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort(start,j-size,size,cmp);
    quicksort(j+size,end,size,cmp);
}
void qsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+(total_elem-1)*size,size,cmp);
}


typedef struct station{
    double distance,oilPrice;
}stn;

int cmp(const void * a,const void * b){
    return (((stn*)a)->distance)-(((stn*)b)->distance);
}
int main(){
    double DCity,Capa,DOil,DCar,total,oil,tempOil;
    stn list[100000];
    int N,i,j;
    while ((total=oil=list[0].distance=0),~scanf("%lf%lf%lf%lf%d",&DCity,&Capa,&DOil,&(list[0].oilPrice),&N)){
        DCar=DOil*Capa;
        for (i=1;i<=N;i++) scanf("%lf%lf",&(list[i].distance),&(list[i].oilPrice));
        list[N+1].distance=DCity,list[N+1].oilPrice=0;
        qsort(list,N+2,sizeof(stn),cmp);
        for (i=0;i<N;i++){
            if (i) oil-=(list[i].distance-list[i-1].distance)/DOil;
            tempOil=(list[i+1].distance-list[i].distance)/DOil;
            if (Capa<tempOil) {
                printf("No Solution\n");goto end;
            }
            if (i<N&&oil<tempOil){
                //should get gas!
                if (list[i].oilPrice>list[i+1].oilPrice){
                    //only get needed gas
                    //printf("too high,get %lf oil,get %lf money,now has %lf total cost\n",tempOil-oil,list[i].oilPrice*(tempOil-oil),total);
                    total+=list[i].oilPrice*(tempOil-oil);
                    oil=tempOil;
                }else{
                    for (j=i+1;list[j].oilPrice>list[i].oilPrice;j++);
                    //printf("next station:(%lf %lf),",list[j].distance,list[j].oilPrice);
                    //printf("need:%lf\n",((list[j].distance-list[i].distance)/DOil));
                    tempOil=min((list[j].distance-list[i].distance)/DOil,Capa);
                    if (tempOil>oil){
                        //printf("cheap,get %lf oil,get %lf money,now has %lf total cost\n",tempOil-oil,list[i].oilPrice*(tempOil-oil),total);
                        total+=list[i].oilPrice*(tempOil-oil);
                        oil=tempOil;
                    }
                }
            }
        }
        oil-=(list[N].distance-list[N-1].distance)/DOil;
        tempOil=(DCity-list[N].distance)/DOil;
        if (Capa<tempOil) {
            printf("No Solution\n");goto end;
        }
        if (oil<tempOil) total+=list[N].oilPrice*(tempOil-oil);
        printf("%.2lf\n",total);
        end:;
    }
    
}