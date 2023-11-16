#include <stdio.h>

void selection_sort(int* arr,int len){
    if (len<2) return;
    int max=0,i;
    for (i=1;i<len;i++) max=arr[max]>arr[i]?max:i;
    if (max==len-1) goto next;
    arr[max]=arr[max]^arr[len-1];
    arr[len-1]=arr[max]^arr[len-1];
    arr[max]=arr[max]^arr[len-1];
    next:selection_sort(arr,len-1);
}

int main(){
    int n,i,arr[1000];
    while (1){
        printf("Enter length of the array: ");scanf("%d",&n);
        printf("Enter the array: ");for (i=0;i<n;i++) scanf("%d",&arr[i]);
        selection_sort(arr,n);
        printf("Sorted array: ");for (i=0;i<n;i++) printf("%d ",arr[i]);
        putchar('\n');
    }
    
    return 0;
}