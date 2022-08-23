// two pointers
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;
        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l++] != nums[r--]) return false;
        }
        return true;
    }
};
