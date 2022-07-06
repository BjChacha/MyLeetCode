// Greedy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 1) return 1;
        
        vector<int> candies(n, 1);
        unordered_map<int, vector<int>> indexes;
        for (int i = 0; i < n; ++i) {
            if (indexes.count(ratings[i]) == 0) indexes[ratings[i]] = {};
            indexes[ratings[i]].push_back(i);
        }
        int res = 0;
        for (int rate = 0; rate <= 20000; ++rate) {
            if (indexes.count(rate)) {
                for (int idx: indexes[rate]) {
                    if (idx == 0) {
                        candies[idx] = ratings[idx] > ratings[idx+1] ? candies[idx+1] + 1 : 1;
                    } else if (idx == n - 1) {
                        candies[idx] = ratings[idx] > ratings[idx-1] ? candies[idx-1] + 1 : 1;
                    } else {
                        int left = ratings[idx] > ratings[idx-1] ? candies[idx-1] + 1 : 1;
                        int right = ratings[idx] > ratings[idx+1] ? candies[idx+1] + 1 : 1;
                        candies[idx] = max(left, right);
                    }
                    res += candies[idx];
                }
            }
        }
        return res;
    }
};