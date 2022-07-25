// layer order
class CBTInserter {
private:
    TreeNode* root;
    vector<TreeNode*> nodes;
    int lastP;

    void layerorder(TreeNode* node) {
        vector<TreeNode*> cur{node};
        vector<TreeNode*> nex;
        while (cur.size()) {
            for (auto& n: cur) {
                nodes.push_back(n);
                if (n->left) nex.push_back(n->left);
                if (n->right) nex.push_back(n->right);
            }
            cur = nex;
            nex = {};
        }
    }
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        layerorder(root);
        lastP = (nodes.size() - 1) >> 1;
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        nodes.push_back(node);
        if (nodes[lastP]->left == nullptr) {
            nodes[lastP]->left = node;
            return nodes[lastP]->val;
        } else {
            nodes[lastP]->right = node;
            return nodes[lastP++]->val;
        }
    }
    
    TreeNode* get_root() {
        return root;
    }
};