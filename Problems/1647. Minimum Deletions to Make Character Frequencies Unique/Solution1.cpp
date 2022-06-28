// priority queue (binary insert)
class Solution {
private:
    int bifind(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1, m;
        while (l <= r) {
            m = (l + r) >> 1;
            if (arr[m] > target) r = m - 1;
            else if (arr[m] < target) l = m + 1;
            else return m;
        }
        return l;
    }
    
public:
    int minDeletions(string s) {
        unordered_map<int, int> counter;
        for (const auto& c: s) {
            if (counter.count(c) == 0) counter[c] = 0;
            counter[c] ++;
        }
        vector<int> arr;
        arr.push_back(0);
        int mn = 100000;
        int res = 0;
        for (const auto& p: counter) {
            
            int i = bifind(arr, p.second);
            if (i < arr.size() && arr[i] == p.second) {
                int j = i;
                while (j - 1 >= 0 && arr[j-1] + 1 == arr[j]) --j;   
                if (j == 0) {
                    res += p.second;
                } else {
                    arr.insert(arr.begin() + j, p.second - i + j - 1);
                    res += i - j + 1;
                }
            } else {
                arr.insert(arr.begin() + i, p.second);
            }
            
        }
        return res;
    }
};