int arraySign(int* nums, int numsSize){
    int negCnt = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) return 0;
        if (nums[i] < 0) negCnt ++;
    }
    return negCnt % 2 == 0 ? 1 : -1;
}
