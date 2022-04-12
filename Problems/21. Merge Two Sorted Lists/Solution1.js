// two pointer
import {ListNode} from '../base.js';

var mergeTwoLists = function(list1, list2) {
    const dummy = new ListNode();
    let p = dummy;
    while (list1 && list2) {
        if (list1.val < list2.val) {
            p.next = list1;
            list1 = list1.next;
        } else {
            p.next = list2;
            list2 = list2.next;
        }
        p = p.next;
    }
    while (list1) {
        p.next = list1;
        p = p.next;
        list1 = list1.next;
    }
    while (list2) {
        p.next = list2;
        p = p.next;
        list2 = list2.next;
    }
    return dummy.next;
};