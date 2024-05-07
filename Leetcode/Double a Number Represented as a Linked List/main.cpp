/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseLinkedList(head);
        ListNode* sum = new ListNode((head->val)*2 % 10);
        ListNode* ans = sum;
        int carry = (head->val * 2)/10;
        head = head->next;
        while(head != nullptr) {
            int double_ = carry + ((head->val) * 2);
            carry = double_ / 10;
            sum->next = new ListNode(double_%10);
            sum = sum->next;
            head = head->next;
        }

        if(carry == 1) {
            sum->next = new ListNode(1);
        }

        return reverseLinkedList(ans);
    }
};
