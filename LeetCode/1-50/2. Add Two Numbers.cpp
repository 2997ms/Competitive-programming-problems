/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {   
        ListNode *pre = new ListNode(0);
        ListNode *res = pre;
        int ex = 0;
        while(l1||l2||ex)
        {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + ex;
            ListNode *a = new ListNode(sum%10);
            ex=sum/10;
            pre->next = a;
            pre = a;
            l1 = l1?l1->next:0;
            l2 = l2?l2->next:0;
        }   
        return res->next;
    }
};