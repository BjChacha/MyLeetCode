#include "../base.hpp"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        // 1. get the length of linknodes
        int n = 0;
        for (ListNode* cur = head; cur; cur=cur->next, ++n) ;
        // 2. locate two nodes to swap
        ListNode *left = dummy, *right = dummy;
        int slow = k - 1, fast = n - k;
        if (slow == fast) return head;
        if (slow > fast) swap(slow, fast);
        int i = 0;
        while (i < slow) {
            left = left->next;
            right = right->next;
            ++i;
        }
        while (i < fast) {
            right = right->next;
            ++i;
        }
        // 3. swap two nodes
        ListNode* tmp = left->next;
        left->next = right->next;
        right->next = tmp;
        tmp = right->next->next;
        right->next->next = left->next->next;
        left->next->next = tmp;

        return dummy->next;
    }
private:
    template <class T>
    void swap(T& a, T& b) {
        T tmp(move(a));
        a = move(b);
        b = move(tmp);
    }
};