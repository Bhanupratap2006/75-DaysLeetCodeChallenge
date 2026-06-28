class Solution {
public:
    void permute(vector<int>&arr,vector<vector<int> > &ans,int index){
        if(index==arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<arr.size();i++){
            swap(arr[i],arr[index]);
            permute(arr,ans,index+1);
            swap(arr[i],arr[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>arr;
        vector<vector<int>>ans;
        permute(nums,ans,0);
        return ans;

        
    }
};