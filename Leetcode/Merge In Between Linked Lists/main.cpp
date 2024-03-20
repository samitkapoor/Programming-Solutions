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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* prev = nullptr;

        for(int i = 0 ; i < b ; i++){
            if(i < a)
                prev = temp;
            temp = temp->next;
        }

        prev->next = list2;

        ListNode* prev2 = nullptr;
        while(list2 != nullptr) {
            prev2 = list2;
            list2 = list2->next;
        }

        prev2->next = temp->next;

        return list1;
    }
};
