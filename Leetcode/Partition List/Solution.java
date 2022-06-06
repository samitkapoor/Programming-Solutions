/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null) return null;
        ListNode smallerThan = new ListNode(0);
        ListNode greaterThan = new ListNode(0);
        ListNode s = smallerThan;
        ListNode g = greaterThan;
        
        while(head != null){
            if(head.val < x){
                s.next = head;
                s = s.next;
            }
            else{
                g.next = head;
                g = g.next;
            }
            
            head = head.next;
        }
        
        g.next = null;
        s.next = greaterThan.next;
        
        return smallerThan.next;
    }
}
