class Solution {
public:

    TreeNode* arrayToBST(vector<int>& arr, int start, int end)
    {
        if(start > end)
            return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = arrayToBST(arr, start, mid - 1);
        root->right = arrayToBST(arr, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return arrayToBST(nums, 0, nums.size() - 1);
    }
};