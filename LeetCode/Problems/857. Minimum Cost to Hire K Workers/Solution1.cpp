// priority queue + greedy
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int &a, int &b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
        });
        priority_queue<int, vector<int>, less<int>> q;
        double res = 1e9, totalq = .0;
        for (int i = 0; i < k - 1; i ++) {
            totalq += quality[idx[i]];
            q.push(quality[idx[i]]);
        }
        for (int i = k - 1; i < n; ++i) {
            totalq += quality[idx[i]];
            q.push(quality[idx[i]]);
            res = min(res, totalq * wage[idx[i]] / quality[idx[i]]);
            totalq -= q.top();
            q.pop();
        }
        return res;
    }
};
