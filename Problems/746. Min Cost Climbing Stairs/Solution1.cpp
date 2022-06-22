// dp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0], second = cost[1], tmp;
        for (int i = 2; i < cost.size(); ++i) {
            tmp = second;
            second = min(second, first) + cost[i];
            first = tmp;
        }
        return min(first, second);
    }
};