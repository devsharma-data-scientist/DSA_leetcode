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
    vector<int> v;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums, 0, nums.size() - 1);
}

    TreeNode* solve(vector<int>& nums, int low, int high) {
        if (low > high)
            return NULL;

        int mid = low + (high - low) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums, low, mid - 1);
        root->right = solve(nums, mid + 1, high);

        return root;
    }

    void recoverTree(TreeNode* root) {
    inorder(root);
    sort(v.begin(), v.end());

    int i = 0;

    function<void(TreeNode*)> change = [&](TreeNode* root) {
        if (root == NULL) return;

        change(root->left);
        root->val = v[i++];
        change(root->right);
    };

    change(root);
}
};