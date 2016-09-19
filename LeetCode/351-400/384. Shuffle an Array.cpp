class Solution {
public:
    vector<int>val;
    Solution(vector<int> nums) 
    {
        srand(time(NULL));
        val=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return val;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int>res(val);
        for(int i=0;i<res.size();i++)
        {
            int j=rand()%(i+1);
            swap(res[i],res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */