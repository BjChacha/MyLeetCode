#include"../base.hpp"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        while (cur) {
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    }
};