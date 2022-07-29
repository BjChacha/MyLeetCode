// dp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > end) return false;
            if (i >= nums.size() - 1) return true;
            end = max(end, i + nums[i]);
        }
        return true;
    }
};