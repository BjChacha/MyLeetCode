// hash table
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        if (n % groupSize) return false;

        unordered_map<int, int> counter;
        priority_queue<int, vector<int>, greater<int>> q;
        for (const auto& num: hand) {
            counter[num] ++;
            q.push(num);
        }
        
        int cur;
        while (!q.empty()) {
            cur = q.top();
            q.pop();
            if (counter[cur] == 0) continue;
            for (int i = 0; i < groupSize; ++i) {
                if (counter[cur+i] == 0) return false;
                counter[cur+i] --;
            }
        }
        return true;
    }
};
