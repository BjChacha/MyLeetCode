// greedy
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modified = 0, pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < pre) {
                if (modified++) return false;
                
                if (i > 1 && nums[i] < nums[i-2]) continue;
            }
            pre = nums[i];
        } 
        return true;
    }
};