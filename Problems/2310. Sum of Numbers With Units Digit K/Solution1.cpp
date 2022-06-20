// hash table
class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (k == 0) return num % 10 == 0 ? 1 : -1;
        unordered_map<int, vector<int>> d {
            {1, {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}},
            {2, {2, 4, 6, 8, 0}},
            {3, {3, 6, 9, 2, 5, 8, 1, 4, 7, 0}},
            {4, {4, 8, 2, 6, 0}},
            {5, {5, 0}},
            {6, {6, 2, 8, 4, 0}},
            {7, {7, 4, 1, 8, 5, 2, 9, 6, 3, 0}},
            {8, {8, 6, 4, 2, 0}},
            {9, {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}},
        };
        auto it = find(d[k].begin(), d[k].end(), num % 10);
        if (it != d[k].end()) { 
            int index = it - d[k].begin() + 1;
            return index * k > num ? -1 : index;
        }
        return -1;
    }
};