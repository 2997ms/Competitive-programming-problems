int flag;
int row[15];
int col[15];
int pick[15][15];

void dfs(int row, vector<string>x, int cnt)
{
    if (cnt >= 5)
    {
        flag = 1;
    }
    if (row == 8)
    {
        return;
    }
    if (flag)return;

    for (int i = 0; i<x[row].length(); i++)
    {

        if (x[row][i] == 'R'&&col[i] == 0)
        {
            pick[row][i] = 1;
            col[i] = 1;
            dfs(row + 1, x, cnt + 1);
            if (flag)return;
            pick[row][i] = 0;
            col[i] = 0;
        }
    }
    dfs(row+1,x,cnt);
}


class FiveRooks
{
public:
vector<int>find(vector<string>x)
{
    flag = 0;
    mem(row,0);
    mem(col,0);
    mem(pick,0);
    dfs(0,x,0);

    vector<int>ans;
    rep(i,0,8)
    {
        rep(j,0,8)
        {
            if(pick[i][j])
            {
                ans.push_back(i);
                ans.push_back(j);
            }
            if(ans.size()>=10)
            {
                break;
            }
        }
        if(ans.size()>=10)
        {
            break;
        }
    }
    rep(i,0,ans.size())
    {
        DE(ans[i])
    }
    return ans;
}
}g;
