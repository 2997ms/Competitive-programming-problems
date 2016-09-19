class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        int i, j, k;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for(i=1;i<sz;i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};