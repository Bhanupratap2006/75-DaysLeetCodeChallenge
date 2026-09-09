/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void mindis(TreeNode*root,int&prev,int&ans)
    {
        if(!root)
        return;
        mindis(root->left,prev,ans);
        if(prev!=INT_MIN)
        ans = min(ans,root->val - prev);
        prev = root->val;
        mindis(root->right,prev,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        mindis(root,prev,ans);
        return ans;

        
    }
};