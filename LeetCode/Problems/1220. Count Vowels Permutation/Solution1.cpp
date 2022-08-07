// dp
class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char, int> c2i = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
        unordered_map<char, vector<char>> lk = {
            {'a', {'e'}},
            {'e', {'a', 'i'}},
            {'i', {'a', 'e', 'o', 'u'}},
            {'o', {'i', 'u'}},
            {'u', {'a'}}
        };
        vector<vector<long>> dp(n, vector<long>(5, 0));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
        for (int i = 1; i < n; ++i) {
            for (const auto& c: {'a', 'e', 'i', 'o', 'u'}) {
                for (const auto& cc: lk[c]) dp[i][c2i[c]] = (dp[i][c2i[c]] + dp[i-1][c2i[cc]]) % 1000000007;
            }
        }
        
        return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4]) % 1000000007;
    }
};
