int app[1000];
int pos[1000];
int idx(char x)
{
    return x;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length()==0)return 0;
        int res = 1;
        for(int i=0;i<s.length();i++)
        {
            int j=i+1;
            app[s[i]]=1;
            while(!app[s[j]]&&j<s.length())
            {
                app[s[j]]=1;
                j++;
            }
            for(int x=i;x<j;x++)
            {
                app[s[x]]=0;
            }
            //cout<<i<<" "<<j-i<<endl;
            res=max(res,j-i);
            app[s[i]]=0;
        }
        return res;
    }
}t;