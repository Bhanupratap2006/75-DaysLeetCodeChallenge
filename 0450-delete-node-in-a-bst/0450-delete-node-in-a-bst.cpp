/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findmax(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root)
            return NULL;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                 
                return NULL;
            }
            if (!root->left) {
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            if (!root->right) {
                TreeNode* child = root->left;
                delete root;
                return child;
            }
            TreeNode* child = findmax(root->left);
            root->val = child->val;
            root->left = deleteNode(root->left, child->val);
        }
        return root;
    }
};