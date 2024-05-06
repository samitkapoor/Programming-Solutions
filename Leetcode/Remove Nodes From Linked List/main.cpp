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
        if(head == nullptr) return nullptr;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr) {
            ListNode* next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseLinkedList(head);
        ListNode* temp = new ListNode(head->val);
        ListNode* ans = temp;

        int maxi = head->val;
        ListNode* curr = head->next;
        while(curr != nullptr) {
            if(curr->val >= maxi) {
                maxi = curr->val;
                temp->next = new ListNode(maxi);
                temp = temp->next;
            }
            curr = curr->next;
        }

        return reverseLinkedList(ans);
    }
};
