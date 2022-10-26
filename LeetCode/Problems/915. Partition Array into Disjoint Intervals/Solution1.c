#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int partitionDisjoint(int* nums, int numsSize){
    int leftMax = nums[0];
    int rightMin[numsSize];
    rightMin[numsSize-1] = nums[numsSize-1];
    for (int i = numsSize - 2; i >= 0; --i) {
        rightMin[i] = MIN(rightMin[i+1], nums[i]);
    }
    for (int i = 1; i < numsSize; ++i) {
        if (leftMax <= rightMin[i]) return i;
        leftMax = MAX(leftMax, nums[i]);
    }
    return numsSize;
}
