class Solution {
public:
    int ans = 0;

    vector<int> solve(TreeNode* root) {
        if (root == NULL)
            return {1, INT_MAX, INT_MIN, 0};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);

        if (left[0] && right[0] &&
            root->val > left[2] &&
            root->val < right[1]) {

            int sum = left[3] + right[3] + root->val;

            ans = max(ans, sum);

            int mn = min(root->val, left[1]);
            int mx = max(root->val, right[2]);

            return {1, mn, mx, sum};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};