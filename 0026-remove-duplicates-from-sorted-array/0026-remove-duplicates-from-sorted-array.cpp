class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        vector<int> ans;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                ans.push_back(nums[i]);
            }
        }

        ans.push_back(nums.back());

        for (int i = 0; i < ans.size(); i++)
        {
            nums[i] = ans[i];
        }

        return ans.size();
    }
};