string change(string x,int pos)
{
    for(int i=pos;i>=0;i--)
    {
        if(x[i]=='A')
        {
            string ans = x.substr(0,i) + "SA" + x.substr(i+1);
            return ans;
        }
    }
    return "SA" + x;
}

class OnlySanta
{
public:
    string solve(string val)
    {
        int fint = -1;
        int finn = -1;
        for(int i=0;i<val.length();i++) {
            if(val[i]=='T')
            {
                fint = i;
                break;
            }
        }
        for(int i=val.length()-1;i>=0;i--)
        {
            if(val[i]=='N')
            {
                finn=i;
                break;
            }
        }
        if(fint==-1&&finn==-1)
        {
            return "SANTA" + val;
        }
        else if(fint==-1)
        {
            string ans = val.substr(0,finn) + "SANTA" + val.substr(finn+1);
            return ans;
        }
        else if(finn==-1)
        {
            string ans = val.substr(0,fint) + "SANTA" + val.substr(fint+1);
            return ans;
        }
        else
        {
            if(finn<fint)
            {
                string ans = "SA" + val + "A";
                return ans;
            }
            else
            {
                string ans = val.substr(0,finn) + "NT" + val.substr(finn+1) + "A";
                ans = change(ans,finn);
                string k = "SATAN";
                int cnt = 0;
                int flag = 0;
                for(int i=0;i<ans.length();i++) {
                    if (ans[i] == k[cnt]) {
                        cnt++;
                    }
                    if (cnt == k.length()) {
                        flag = 1;
                    }
                }
                if(flag==0)
                {
                    return ans;
                }
                ans = val.substr(0,fint) + "NT" + val.substr(fint+1) + "A";
                ans = change(ans,fint);
                return ans;
            }
        }
        return "";
    }
};