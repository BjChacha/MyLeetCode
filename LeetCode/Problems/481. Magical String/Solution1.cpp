// queue
class Solution {
public:
    int magicalString(int n) {
        deque<int> arr = {2};
        int res = 1, t = 1, size = 3, cnt;
        while (size < n) {
            cnt = arr.front();
            arr.pop_front();
            for (int c = 0; c < cnt; ++c) arr.push_back(t);
            if (t == 1) res += cnt;
            size += cnt;
            t = 3 - t;
        }
        if (t == 2) res -= (size - n);
        return res;
    }
};
