// 
var deleteNode = function(head, val) {
    const dummy = new ListNode();
    dummy.next = head;
    let cur = dummy;
    while (cur.next) {
        if (cur.next.val === val) {
            cur.next = cur.next.next;
            break;
        }
        cur = cur.next;
    }
    return dummy.next;
};