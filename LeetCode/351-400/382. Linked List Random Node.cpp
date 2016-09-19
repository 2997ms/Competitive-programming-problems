/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int>v;
    Solution(ListNode* head) 
    {
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        //srand(time(NULL));
        int sz=v.size();
        int k=rand()%(sz);
        return v[k];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */