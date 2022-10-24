// prefix array
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        const int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMin(n);
        leftMax[0] = nums[0];
        rightMin[n-1] = nums[n-1];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i-1], nums[i]);
            rightMin[n-i-1] = min(rightMin[n-i], nums[n-i-1]);
        }
        for (int i = 1; i < n; ++i) {
            if (leftMax[i-1] <= rightMin[i]) return i;
        }
        return n;
    }
};
