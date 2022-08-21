// max heap
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel) return 0;
        proirity_queue<int, vector<int>, less<int>> heap;
        int remain = startFuel, pos = 0, res = 0, n = stations.size();
        while (remain < target) {
            for (int i = pos; i < n; ++i) {
                if (remain >= stations[i][0]) {
                    heap.push(stations[i][1]);
                    pos ++;
                }
            }
            if (remain < target) {
                if (heap.size() == 0) return -1;
                remain += heap.top();
                heap.pop();
                res += 1;
            }
        }
        return res;
    }
};
