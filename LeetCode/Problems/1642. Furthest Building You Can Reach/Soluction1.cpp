// priority queue
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0, diff;
        for (int i = 1; i < heights.size(); i ++) {
            diff = heights[i] - heights[i-1];
            if (diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    if (pq.top() > bricks) return i - 1;
                    bricks -= pq.top();
                    pq.pop();
                }
            }
        }
        return heights.size() - 1;
    }
};