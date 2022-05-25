bool cmp(vector<int>&a1, vector<int>&a2)
{
    if (a1[0] == a2[0])return a1[1] > a2[1];
    else return a1[0] < a2[0];
}

int val[100005];
class Solution 
{
public:
    int maxEnvelopes(vector<vector<int> >& env) 
    {
       // memset(val, -1, sizeof(val));
        sort(env.begin(), env.end(), cmp);
        int sz = env.size();
        int len = 0;
        for (int i = 0; i < sz; i++)
        {
            if (len == 0 || env[i][1] > val[len])
            {
                len++;
                val[len] = env[i][1];
            }
            else
            {
                int pos = lower_bound(val+1, val+1+len, env[i][1]) - val;
                val[pos] = env[i][1];
            }
        }
        return len;
    }
}wc;