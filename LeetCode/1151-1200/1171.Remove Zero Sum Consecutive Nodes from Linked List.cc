class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL) return NULL;
         vector<int> v;
         ListNode* t = head;
        while(t != NULL) {
            v.push_back(t->val);
            t = t->next;
        }
        while(true) {
            map<int,int>hax;
            hax[0] = -1;
            int sum = 0;
            int le = 0;
            int ri = 0;
            int flag = 0;
            for(int i=0;i<v.size();i++) {
                sum += v[i];
                if(hax.count(sum)) {
                    flag = 1;
                    le = hax[sum]+1;
                    ri = i;
                    break;
                }
                hax[sum] = i;
            }
            if(flag == 0) {
                break;
            } else {
                vector<int>nxt;
                for(int i=0;i<v.size();i++) {
                    if(i>=le&&i<=ri)continue;
                    nxt.push_back(v[i]);
                }
                v = nxt;
            }
        }
        ListNode* res = new ListNode(-1);
        ListNode* tg = res;
        if(v.size()>0) {
            tg->val = v[0];
            rep(i,1,v.size()) {
                ListNode* tmp = new ListNode(v[i]);
                tg->next = tmp;
                tg = tmp;
            }
            return res;
        } else {
            return NULL;
        }
    }
};