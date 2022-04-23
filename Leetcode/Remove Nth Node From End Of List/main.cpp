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
    int lengthOfList(ListNode *head)
    {
        int counter = 0;
        while (head != NULL)
        {
            head = head->next;
            counter++;
        }

        return counter;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int x = lengthOfList(head);
        if (x == 1)
            return NULL;
        n = x - n;
        ListNode *temp = head;
        ListNode *prev = head;
        while (n--)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            temp = NULL;
            prev->next = NULL;
        }
        else if (temp == prev)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        return head;
    }
};