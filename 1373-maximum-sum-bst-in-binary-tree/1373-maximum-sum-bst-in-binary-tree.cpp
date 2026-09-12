class Solution {
public:
    class box {
    public:
        bool BST;
        int sum, min, max;

        box() {
            BST = true;
            sum = 0;
            min = INT_MAX;
            max = INT_MIN;
        }

        box(bool b, int s, int mn, int mx) {
            BST = b;
            sum = s;
            min = mn;
            max = mx;
        }
    };

    box* find(TreeNode* root, int& totalsum) {

        if (!root)
            return new box();

        box* L = find(root->left, totalsum);
        box* R = find(root->right, totalsum);

        if (L->BST && R->BST &&
            L->max < root->val &&
            root->val < R->min) {

            box* head = new box(
                true,
                L->sum + R->sum + root->val,
                min(root->val, L->min),
                max(root->val, R->max)
            );

            totalsum = max(totalsum, head->sum);

            return head;
        }

        return new box(false, 0, 0, 0);
    }

    int maxSumBST(TreeNode* root) {
        int totalsum = 0;

        find(root, totalsum);

        return totalsum;
    }
};