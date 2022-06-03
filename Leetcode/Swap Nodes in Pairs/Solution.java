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
    public ListNode swapPairs(ListNode head) {
        ListNode temp = new ListNode(0, head);
        ListNode curr = temp;
        
        while(curr.next != null && curr.next.next != null){

            ListNode firstNode = curr.next;
            ListNode secondNode = curr.next.next;
            
            firstNode.next = secondNode.next;
            curr.next = secondNode;
            curr.next.next = firstNode;
            curr = curr.next.next;
        
        }
        
        return temp.next;
    }
}
