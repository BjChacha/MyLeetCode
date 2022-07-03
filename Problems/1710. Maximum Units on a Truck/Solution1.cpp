// sort, simulate
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int> a, const vector<int> b) {
            return a[1] > b[1];
        });
        int res = 0, i = 0;
        while (truckSize > 0) {
            res += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            truckSize -= min(truckSize, boxTypes[i][0]);
            if (++i >= boxTypes.size()) break;
            
        }
        return res;
    }
};