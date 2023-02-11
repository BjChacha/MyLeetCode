class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        return amount[2] + max(0, (amount[0] + amount[1] - amount[2] + 1) / 2); 
    }
};
