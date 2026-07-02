class Solution {
public:
    vector<int>ans;
    bool solve(vector<int>&nums,int target,int i,int j){
        if(i>=nums.size()){
            return false;
        }
        if(j>=nums.size()){
            return solve(nums,target,i+1,i+2);

        }
        if(nums[i]+nums[j]==target){
            ans={i,j};
            return true;
        }
        return solve(nums,target,i,j+1);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        solve(nums,target,0,1);
        return ans;

        
    }
};