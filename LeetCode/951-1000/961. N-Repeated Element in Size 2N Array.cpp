class Solution
{
public:
  int repeatedNTimes(vector<int> &A)
  {
    map<int, int> hax;
    for (int i = 0; i < A.size(); i++)
    {
      hax[A[i]]++;
      if (hax[A[i]] > 1)
        return A[i];
    }
    return -1;
  }
};