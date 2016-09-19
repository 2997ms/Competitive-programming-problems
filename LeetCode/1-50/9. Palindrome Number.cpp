class Solution {
public:
    bool isPalindrome(long long x) 
    {
        if(x<0)
        {
            return false;
        }
        if(x==0)
        {
            return true;
        }
        long long len;
        for(len=1;;len*=10)
        {
            if(x/len==0)
            {
                break;
            }
        }
        len/=10;
        //cout<<(len)<<endl;
        while(x&&len>=2)
        {
            int ri=x%10;
            int le=x/len;
            if(le!=ri)
            {
                //cout<<le<<" "<<ri<<endl;
                return false;
            }
            x/=10;
            //cout<<x<<endl;
            x=x%(len/10);
            //cout<<x<<endl;
            //cout<<len<<endl;
            //cout<<le<<" "<<ri<<endl;
            len/=100;
        }
        return true;
    }
}t;