// Union Set & Hash
class UnionSet {
private:
    vector<int> rank, root;
public:
    UnionSet(int size) {
        rank = vector<int>(size, 1);
        root = vector<int>(size);
        
        for (int i = 0; i < size; ++i) root[i] = i;
    }
    
    int find(int x) {
        int rootX = root[x];
        while (rootX != root[rootX]) {
            rootX = root[rootX];
        }
        return root[x] = rootX;
    }
    
    void un(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            } else {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        UnionSet us = UnionSet(100001);
        unordered_map<int, int> memo;
        int res = 0;
        
        for (auto& num: nums) {
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) {
                    us.un(num, i);
                    us.un(num, num / i);
                }
            }
        }
        for (auto& num: nums) 
            res = max(res, ++memo[us.find(num)]);
        
        return res;
    }
};