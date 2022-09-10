// sorting
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            string x = to_string(a), y = to_string(b);
            return y + x < x + y;
        });
        string res = "";
        for (const auto& num: nums) 
            res += to_string(num);
        return res[0] == '0' ? "0" : res;
    }
};
