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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;

        while ((fast != nullptr) && (fast->next != nullptr))
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reversing the second half of the linked list
        ListNode *prev = NULL;
        ListNode *temp = slow;
        while (temp != NULL)
        {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        slow = prev;
        fast = head;

        while (fast != NULL && slow != NULL)
        {
            if (fast->val != slow->val)
            {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};