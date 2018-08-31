/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
    let l = head
    let prev = null
    let begin = { ...l }

    while (l) {
        l.prev = prev
        prev = { ...l }
        l = l.next
    }

    let last = { ...prev }

    while (begin != last) {
        if (begin.val != last.val) return false;
        begin = begin.next;
        last = last.prev;
    }

    return true
};
