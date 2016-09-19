class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int sz = nums.size();
        if (sz == 0)
        {
            return 0;
        }
        int idx = sz - 1;
        for (int i = sz - 1; i >= 0; i--)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[idx]);
                idx--;
                sz--;
            }
        }
        nums.resize(sz);
        return sz;
    }
};