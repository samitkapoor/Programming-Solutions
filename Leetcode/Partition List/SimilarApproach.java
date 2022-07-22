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
        ListNode temp = head;
        
        ListNode before_head = new ListNode(0);
        ListNode before = before_head;
        ListNode after_head = new ListNode(0);
        ListNode after = after_head;
        
        while(temp != null){
            if(temp.val < x){
                before.next = new ListNode(temp.val);
                before = before.next;
            }
            else{
                after.next = new ListNode(temp.val);
                after = after.next;
            }
            
            temp = temp.next;
        }
        
        before.next = after_head.next;
        
        return before_head.next;        
    }
}
