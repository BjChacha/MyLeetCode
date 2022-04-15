// fast&slow pointers
var getKthFromEnd = function(head, k) {
    let fast = head, slow = head;
    while (--k) fast = fast.next;
    while (fast.next) {
        fast = fast.next;
        slow = slow.next;
    }
    return slow;
};