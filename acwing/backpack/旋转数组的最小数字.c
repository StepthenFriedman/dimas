int findMin(int* nums, int numsSize) {
    if (!numsSize) return -1;
    for (int i=0;i<numsSize-1;i++) if (nums[i]>nums[i+1]) return (nums[i+1]<nums[0]?nums[i+1]:nums[0]);
    return nums[0];
}
