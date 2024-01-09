#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fruit{
    char name[85]; int num;
}fruit;

typedef struct city{
    char name[85];
    fruit* list;
    int len;
}city;

int cmpFruit(const void *a,const void *b){
    return strcmp(((fruit*)a)->name,((fruit*)b)->name);
}

int cmpCity(const void *a,const void *b){
    return strcmp(((city*)a)->name,((city*)b)->name);
}

void printCity(city *c){
    printf("%s\n",c->name);
    for (int i=0;i<c->len;i++) printf("|----%s(%d)\n",c->list[i].name,c->list[i].num);
}

void sortFruit(city *c){
    qsort(c->list,c->len,sizeof(fruit),cmpFruit);
}

city cities[1000];
int main(){
    int year,month,day,n,i,cityNum;
    char ipt1[85],ipt2[85]; int ipt3;
    while (~scanf("%d/%d/%d%d",&year,&month,&day,&n)){
        cityNum=0;
        while (n--){
            int cityHandle=0,fruitHandle=0;
            scanf("%s%s%d",&ipt1,&ipt2,&ipt3);
            for (i=0;i<cityNum;i++) if (!strcmp(ipt2,cities[i].name)){
                cityHandle=i;goto next1;
            }
            strcpy(cities[cityNum].name,ipt2);
            cities[cityNum].len=0;
            cities[cityNum].list=(fruit*)malloc(1000*sizeof(fruit));

            cityHandle=cityNum++;
            next1:;
            int len1=cities[cityHandle].len;
            for (i=0;i<len1;i++) if (!strcmp(ipt1,(cities[cityHandle].list[i].name))){
                fruitHandle=i;goto next2;
            }
            strcpy(cities[cityHandle].list[len1].name,ipt1);
            cities[cityHandle].list[len1].num=0;
            fruitHandle=cities[cityHandle].len++;
            next2:
            cities[cityHandle].list[fruitHandle].num+=ipt3;
        }
        qsort(cities,cityNum,sizeof(city),cmpCity);
        printf("%d.%d.%d\n",year,month,day);
        for (i=0;i<cityNum;i++) sortFruit(cities+i),
        printCity(cities+i);
    }
    return 0;
}