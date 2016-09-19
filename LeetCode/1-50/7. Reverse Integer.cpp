//注意10，100这种情况
//注意越界
class Solution
{
public:
    int reverse(int x)
    {
        if(x==0)return 0;
        int f=0;
        if(x<0)
        {
            f=1;
            x=-x;
        }
        int dig[20];
        int cnt=0;
        while(x)
        {
            cnt++;
            dig[cnt]=x%10;
            x/=10;
        }
        long long res=0;
        for(int i=1;i<=cnt;i++)
        {
            res=res*10+dig[i];
        }
        if(f)
        {
            res=-res;
        }
        //cout<<res<<endl;
        if(res>2147483648||res<-2147483648)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
}t;