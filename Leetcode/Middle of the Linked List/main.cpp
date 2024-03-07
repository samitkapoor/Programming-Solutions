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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* turtle = head;
        ListNode* rabbit = head;
        while(rabbit != nullptr && rabbit->next != nullptr) {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }

        return turtle;
    }
};
