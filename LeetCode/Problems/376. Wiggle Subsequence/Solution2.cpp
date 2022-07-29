// Greedy 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        int prediff = nums[1] - nums[0], curdiff;
        int res = prediff == 0 ? 1 : 2;
        for (int i = 2; i < n; ++i) {
            curdiff = nums[i] - nums[i-1];
            if ((curdiff < 0 && prediff >= 0) || (curdiff > 0 && prediff <= 0)) {
                prediff = curdiff;
                res ++;
            }
        }
        return res;
    }
};