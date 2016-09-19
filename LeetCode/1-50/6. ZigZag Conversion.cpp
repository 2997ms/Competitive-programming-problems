class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)return s;
        int len=s.length();
        string res="";

        int gap = (numRows<<1) - 2;
        for(int i=0;i<len;i+=gap)//处理第一行
        {
            res=res+s[i];
        }

        for(int i=1;i<=numRows-2;i++)//处理第一行到倒数第二行
        {
            int inter=i<<1;
            for(int j=i;j<len;j+=inter)
            {
                res=res+s[j];
                inter=gap-inter;
            }
        }
        for(int i=numRows-1;i<len;i+=gap)//处理最后一行
        {
            res=res+s[i];
        }
        return res;
    }
}t;