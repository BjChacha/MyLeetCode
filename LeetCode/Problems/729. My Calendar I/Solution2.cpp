// balanced tree
class BalancedNode {
private:
    int start, end;
    BalancedNode *left, *right;
public:
    BalancedNode(int a, int b) {
        start = a;
        end = b;
        left = right = nullptr;
    }

    bool insert(int a, int b) {
        if (a >= end) {
            if (right) return right->insert(a, b);
            right = new BalancedNode(a, b);
            return true;
        } else if (b <= start) {
            if (left) return left->insert(a, b);
            left = new BalancedNode(a, b);
            return true;
        } else {
            return false;
        }
    }
};

class MyCalendar {
private:
    BalancedNode *root;
public:
    MyCalendar() {
        root = nullptr;
    }
    
    bool book(int start, int end) {
        if (root) return root->insert(start, end);
        root = new BalancedNode(start, end);
        return true;
    }
};
