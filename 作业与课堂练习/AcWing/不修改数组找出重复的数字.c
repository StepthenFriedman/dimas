#include <stdio.h>

int duplicateInArray(int *nums, int numsSize){
	int fast=0,slow=0;
    do{
        fast=nums[nums[fast]];
        slow=nums[slow];
        printf("f:%d s:%d\n",fast,slow);
    }
    while (fast != slow);
	slow = 0;
    while (1){
        fast = nums[fast];
        slow = nums[slow];
        if (fast == slow) return slow;
    }
}

int main(){
	int nums[5]={3,2,1,4,4};
	printf("%d\n",duplicateInArray(nums,5));
}
