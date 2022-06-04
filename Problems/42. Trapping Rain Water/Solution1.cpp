// mono-stack
class Solution {
    public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (stk.size() && height[stk.top()] <= height[i]) {
                int bot = height[stk.top()];
                stk.pop();
                if (stk.size()) {
                    int left = stk.top();
                    int w = i - left - 1;
                    int h = min(height[left], height[i]) - bot;
                    res += w * h;
                }
            }
            stk.push(i);
        }
        return res;
    } 
};