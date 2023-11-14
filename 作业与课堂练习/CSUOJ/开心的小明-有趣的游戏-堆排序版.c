#include <stdio.h>
#include <stdlib.h>
 
void heapify(int* arr, int start, int end) {
    int smallest=start,left = 2*start+1,right=left+1;
    if (left<end&& arr[left]<arr[smallest]) smallest=left;
    if (right<end&& arr[right]<arr[smallest]) smallest=right;
    if (smallest != start) {
        arr[start]=arr[start]^arr[smallest];
        arr[smallest]=arr[start]^arr[smallest];
        arr[start]=arr[start]^arr[smallest];
        heapify(arr,smallest,end);
    }
}
 
int mergePiles(int* arr, int n) {
    int cost = 0;
    while (n > 1) {
        int min1=arr[0];
        arr[0]=arr[--n];
        heapify(arr,0,n);
        cost+=arr[0]+=min1;
        heapify(arr,0,n);
    }
    return cost;
}
int main() {
    int n,i;
    scanf("%d", &n);
    int a[n];
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=n/2-1;i>=0;i--) heapify(a,i,n);
    printf("%d\n", mergePiles(a, n));
 
    return 0;
}