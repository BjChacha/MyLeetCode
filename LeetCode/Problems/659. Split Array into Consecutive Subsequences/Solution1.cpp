// hash table + greedy
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> numCnt;
        unordered_map<int, int> seqCnt;

        for (const auto& num: nums) numCnt[num] ++;

        for (const auto& num: nums) {
            if (numCnt[num] == 0) continue;
            if (seqCnt[num-1] > 0) {
                seqCnt[num-1] --;
                seqCnt[num] ++;
                numCnt[num] --;
            } else {
                if (!numCnt[num+1] > 0 || !numCnt[num+2] > 0) return false;
                numCnt[num] --;
                numCnt[num+1] --;
                numCnt[num+2] --;
                seqCnt[num+2] ++;
            }
        }
        return true;
    }
};
