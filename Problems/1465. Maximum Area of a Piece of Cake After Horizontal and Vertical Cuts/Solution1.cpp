// Greedy
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int preH = 0, preW = 0;
        int maxH = h - horizontalCuts[horizontalCuts.size()-1], maxW = w - verticalCuts[verticalCuts.size()-1];
        for (const int& c: horizontalCuts) {
            maxH = max(maxH, c - preH);
            preH = c;
        }
        for (const int& c: verticalCuts) {
            maxW = max(maxW, c - preW);
            preW = c;
        }
        return (int)(((long)maxH * (long)maxW) % 1000000007);
    }
};