class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        
            vector<int>ans;
            for(int i=0;i<nums.size();i++){
                ans.push_back(nums[i]);

            }

        stack<int> st;
        for(int i=0;i<nums.size();i++){
            st.push(nums[i]);

        }
        int i =0;
        while(! st.empty()){
            ans.push_back(st.top());
            i++;
            st.pop();
        }
        return ans;
        
    

        
    }
};