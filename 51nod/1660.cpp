/*贪心*/
int n;
char val[maxn];

void solve()
{
  scanf("%s", val + 1);
  n = strlen(val + 1);

  reverse(val + 1, val + n + 1);
  val[n + 1] = '0';
  int ans = 0;
  repp(i, 1, n + 1)
  {
    if (val[i] == '2')
    {
      val[i + 1]++;
    }
    else if (val[i] == '1')
    {
      if (val[i + 1] == '1')
      {
        val[i + 1]++;
      }
      ans++;
    }
  }
  cout << ans << endl;
}
