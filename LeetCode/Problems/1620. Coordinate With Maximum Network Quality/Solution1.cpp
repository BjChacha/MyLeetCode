// bruce force
class Solution {
private:
    double getDistance(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        double maxIntensity = 0.0;
        vector<int> res = {0, 0};
        double t_dis;
        int t_int;
        for (int x = 0; x <= 50 + radius; ++x) {
            for (int y = 0; y <=  50 + radius; ++y) {
                t_int = 0;
                for (auto tower: towers) {
                    t_dis = getDistance(x, y, tower[0], tower[1]);
                    if (t_dis <= radius * radius) {
                        t_int += (int)tower[2] / (1 + sqrt(t_dis));
                    }
                }
                if (t_int > maxIntensity) {
                    maxIntensity = t_int;
                    res = {x, y};
                }
            }
        }
        return res;
    }
};
