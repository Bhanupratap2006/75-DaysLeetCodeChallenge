class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0, end = 0;
        int n = nums.size();
        int total = INT_MAX;

        while(end < n)
        {
            sum += nums[end];

            while(sum >= target)
            {
                total = min(total, end - start + 1);

                sum -= nums[start];
                start++;
            }

            end++;
        }

        if(total == INT_MAX)
            return 0;

        return total;
    }
};