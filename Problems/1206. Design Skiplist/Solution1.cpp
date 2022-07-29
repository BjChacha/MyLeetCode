// Skiplist
constexpr float P = 0.5;
constexpr int MAX_SIZE = 16;

struct SkiplistNode {
    int val;
    vector<SkiplistNode*> fw;
    SkiplistNode(int _val=-1, int _size=MAX_SIZE): val(_val), fw(_size, nullptr) {};
};

class Skiplist {
private:
    SkiplistNode* head;
    int maxLevel;
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
public:
    Skiplist(): head(new SkiplistNode()), maxLevel(0), dis(0, 1) {}
    
    bool search(int target) {
        SkiplistNode *cur = head;
        for (int i = maxLevel - 1; i >= 0; --i) {
            while (cur->fw[i] && cur->fw[i]->val < target) cur = cur->fw[i];
        }
        if (cur->fw[0] && cur->fw[0]->val == target) return true;
        return false;
    }
    
    void add(int num) {
        vector<SkiplistNode*> update(MAX_SIZE, head);
        SkiplistNode* cur = head;
        for (int i = maxLevel - 1; i >= 0; --i) {
            while (cur->fw[i] && cur->fw[i]->val < num) cur = cur->fw[i];
            update[i] = cur;
        }
        int level = randomLevel();
        maxLevel = max(maxLevel, level);
        SkiplistNode *newNode = new SkiplistNode(num, level);
        for (int i = 0; i < level; ++i) {
            newNode->fw[i] = update[i]->fw[i];
            update[i]->fw[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode*> update(MAX_SIZE, head);
        SkiplistNode* cur = head;
        for (int i = maxLevel - 1; i >= 0; --i) {
            while (cur->fw[i] && cur->fw[i]->val < num) cur = cur->fw[i];
            update[i] = cur;
        } 
        cur = cur->fw[0];
        if (!cur || cur->val != num) return false;
        for (int i = 0; i < maxLevel; ++i) {
            if (update[i]->fw[i] == cur) {
                update[i]->fw[i] = cur->fw[i];
            }
        }
        delete cur;
        while (maxLevel > 1 && head->fw[maxLevel-1] == nullptr) maxLevel --;
        return true;
    }

    int randomLevel() {
        int level = 1;
        while (dis(gen) < P && level < MAX_SIZE) ++level;
        return level;
    }
};