// math
class Solution {
private:
    vector<int> getEdgeVector(vector<int>& p1, vector<int>& p2) {
        return {p2[0] - p1[0], p2[1] - p1[1]};
    }
    
    int getEdgeLength(vector<int> e) {
        return e[0] * e[0] + e[1] * e[1];
    }
    
    bool isOrth(vector<int> e1, vector<int> e2) {
        return e1[0] * e2[0] + e1[1] * e2[1] == 0;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> ps {p1, p2, p3, p4};
        sort(ps.begin(), ps.end());
        vector<int> e1 = getEdgeVector(ps[0], ps[1]);
        vector<int> e2 = getEdgeVector(ps[1], ps[3]);
        vector<int> e3 = getEdgeVector(ps[3], ps[2]);
        vector<int> e4 = getEdgeVector(ps[2], ps[0]);
        return (
            (e1[0] != 0 || e1[1] != 0) &&
            getEdgeLength(e1) == getEdgeLength(e2) && 
            isOrth(e1, e2) &&
            isOrth(e2, e3) &&
            isOrth(e3, e4) &&
            isOrth(e4, e1));
    }
};