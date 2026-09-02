class Solution {
public:

    void find(TreeNode* root, int pos, int& l, int& r) {

        if (!root)
            return;

        l = min(l, pos);
        r = max(r, pos);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if (!root)
            return {};

        int l = 0, r = 0;

        find(root, 0, l, r);

        vector<vector<pair<int, int>>> positive(r + 1);
        vector<vector<pair<int, int>>> negative(abs(l) + 1);

        queue<TreeNode*> q;
        queue<pair<int, int>> index;

        q.push(root);
        index.push({0, 0});

        while (!q.empty()) {

            TreeNode* temp = q.front();
            q.pop();

            int pos = index.front().first;
            int row = index.front().second;
            index.pop();

            if (pos >= 0)
                positive[pos].push_back({row, temp->val});
            else
                negative[abs(pos)].push_back({row, temp->val});

            if (temp->left) {
                q.push(temp->left);
                index.push({pos - 1, row + 1});
            }

            if (temp->right) {
                q.push(temp->right);
                index.push({pos + 1, row + 1});
            }
        }

        vector<vector<int>> ans;

        for (int i = negative.size() - 1; i > 0; i--) {

            sort(negative[i].begin(), negative[i].end());

            vector<int> v;

            for (int j = 0; j < negative[i].size(); j++) {
                v.push_back(negative[i][j].second);
            }

            ans.push_back(v);
        }

        for (int i = 0; i < positive.size(); i++) {

            sort(positive[i].begin(), positive[i].end());

            vector<int> v;

            for (int j = 0; j < positive[i].size(); j++) {
                v.push_back(positive[i][j].second);
            }

            ans.push_back(v);
        }

        return ans;
    }
};