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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode result;
        
        if(list1 == null) return list2;
        else if(list2 == null) return list1;
        
        if(list1.val <= list2.val) {
            result = list1;
            list1 = list1.next;                           
        }
        else{
            result = list2;
            list2 = list2.next;
        }    
        
        ListNode head = result;
        
        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                result.next = list1;
                list1 = list1.next;
            }
            else{
                result.next = list2;
                list2 = list2.next;
            }
            
            result = result.next;
        }
        
        if(list1 != null){
            result.next = list1;
        }
        
        if(list2 != null){
            result.next = list2;
        }      
        
        return head;
    }
}
