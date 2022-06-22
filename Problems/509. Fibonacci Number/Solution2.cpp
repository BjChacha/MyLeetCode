// memo search
class Solution {
private:
    vector<int> cache;
public:
    Solution(): cache(31, -1){};
    int fib(int n) {
        if (n <= 1) return n;
        if (cache[n] > -1) return cache[n];
        return cache[n] = fib(n - 1) + fib(n - 2);;
    }
};