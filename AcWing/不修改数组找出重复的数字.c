int duplicateInArray(int *nums, int numsSize){
	int fast = 0;
    int slow = 0;

    do
    {
        fast = nums[fast];
        fast = nums[fast];
        slow = nums[slow];
    }
    while  (fast != slow);
	slow = 0;
    while (1)
    {
        fast = nums[fast];
        slow = nums[slow];
        if (fast == slow) return slow;
    }
}
