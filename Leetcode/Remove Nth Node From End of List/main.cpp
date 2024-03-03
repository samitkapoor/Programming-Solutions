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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            length++;
            temp = temp->next;
        }

        if(length - n == 0 && length != 1) return head->next;
        if(length == n) return nullptr;

        int remove = length - n - 1;
        temp = head;

        while(remove--) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};
