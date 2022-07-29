// 头插法反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = tmp;
        }
        return dummy->next;
    }
};