#include <stdio.h>
#include <string.h>

typedef struct line{
    int st;int end;int inter;int valid;
}line;


int isin(char* arr, char c){
    for (int i=0;arr[i]!='\0';i++) if (c==arr[i]) return 1;
    return 0;
}

int main(){
    char ipt1[1010],ipt2[1010],arr1[1010],arr2[1010],inter,index,res;
    line lines[1010];
    int i,j,k,l,len,len2;
    while (~scanf("%s%s",&ipt1,&ipt2)){
        for (i=j=k=0;ipt1[i]!='\0';i++) if (isin(ipt2,ipt1[i])) arr1[j++]=ipt1[i];
        arr1[j]='\0';len=j;
        if (!j) {printf("0\n");continue;}
        for (i=j=0;ipt2[i]!='\0';i++) if (isin(arr1,ipt2[i])) arr2[j++]=ipt2[i];
        arr2[j]='\0';
        len=strlen(arr1);len2=strlen(arr2);
        for (i=0;i<len;i++){
            for (j=0;j<len2;j++){
                if (arr2[j]!=' '&&arr1[i]==arr2[j]){
                    inter=0;
                    for (l=0;l<k;l++){
                        if ((lines[l].st-i)*(lines[l].end-j)<=0) lines[l].inter++,inter++;
                    }
                    line nl={i,j,inter,1};
                    lines[k++]=nl;
                    arr2[j]=' ';
                    goto next;
                }
            }
            next:;
        }
        while (1){
            res=inter=index=0;
            for (i=0;i<k;i++) if (lines[i].valid) {
                res++;
                if (inter<lines[i].inter) inter=lines[i].inter,index=i;
            }
            if (!inter) break;
            lines[index].valid=0;
            for (i=0;i<k;i++) if (lines[i].valid) if ((lines[i].st-lines[index].st)*(lines[i].end-lines[index].end)<=0) lines[i].inter--;
        }
        printf("%d\n",res);
    }
}