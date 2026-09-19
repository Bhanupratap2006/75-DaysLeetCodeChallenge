class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
                
        long long total = 0;
        unordered_map<long long, long long> m;
        
        long long prefixsum = 0;
        m[0] = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            prefixsum += nums[i];
            
            if(m.count(prefixsum - k ))
            {
                total += m[prefixsum - k ];
                m[prefixsum]++;
            }
            else
            {
                m[prefixsum]++;
            }
        }
        
        return total;
        
    }
};