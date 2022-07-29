// slide window
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res = 0, tmp = 0;
        for (int i = 0; i < k; ++i) tmp += cardPoints[i];
        
        res = tmp;
        if (k == n) return res;
        
        for (int i = 0; i < k; ++i) 
            res = max(res, tmp += (cardPoints[n-i-1] - cardPoints[k-i-1]));
        
        return res;
    }
};