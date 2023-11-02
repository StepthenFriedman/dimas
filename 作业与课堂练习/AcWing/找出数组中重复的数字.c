int duplicateInArray(int *nums, int numsSize){
	int i,j;
	for (i=0;i<numsSize;i++) if (nums[i]<0||nums[i]>=numsSize-1) return -1;
    for (i=0;i<numsSize;i++) for (j=i+1;j<numsSize;j++) if (nums[i]==nums[j]) return nums[i];
    return -1;
}
