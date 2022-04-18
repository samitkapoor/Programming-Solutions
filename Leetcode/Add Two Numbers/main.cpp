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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool carry = false;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *p1 = NULL;

        while (t1 != NULL && t2 != NULL)
        {
            int temp = 0;
            if (carry == true)
            {
                temp = ((t1->val) + (t2->val)) + 1;
                carry = false;
            }
            else
            {
                temp = ((t1->val) + (t2->val));
                carry = false;
            }

            if (temp >= 10)
            {
                carry = true;
                temp = temp % 10;
            }

            t1->val = temp;
            p1 = t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        if (t2 != NULL)
        {
            p1->next = t2;
        }

        if (carry)
        {
            t1 = p1;
            p1 = p1->next;
            while (carry && p1 != NULL)
            {
                int temp = ((p1->val) + 1);
                if (temp >= 10)
                {
                    temp = temp % 10;
                    carry = true;
                }
                else
                {
                    carry = false;
                }
                p1->val = temp;
                t1 = p1;
                p1 = p1->next;
            }
            if (carry)
            {
                ListNode *newnode = new ListNode();
                newnode->val = 1;
                newnode->next = NULL;
                t1->next = newnode;
            }
        }

        return l1;
    }
};