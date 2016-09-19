int v1[30],v2[30];
int idx(char x)
{
    return x-'a';
}
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));

        for(int i=0;i<ransomNote.length();i++)
        {
            v1[idx(ransomNote[i])]++;
        }
        for(int i=0;i<magazine.length();i++)
        {
            v2[idx(magazine[i])]++;
        }
        for(int i=0;i<26;i++)
        {
            if(v1[i]>v2[i])
                return false;
        }
        return true;
    }
};