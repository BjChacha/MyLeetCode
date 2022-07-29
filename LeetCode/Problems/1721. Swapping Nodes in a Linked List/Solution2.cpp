#include "../base.hpp"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast = nullptr, *slow = nullptr;
        for (ListNode *cur = head; cur; cur = cur->next) {
            fast = fast == nullptr ? nullptr : fast->next;
            if (--k == 0) {
                slow = cur;
                fast = head;
            }
        }
        swap(slow->val, fast->val);
        return head;
    }
private:
    template <class T>
    void swap(T& a, T& b) {
        T tmp(move(a));
        a = move(b);
        b = move(tmp);
    }
};