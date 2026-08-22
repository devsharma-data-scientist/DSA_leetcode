class Solution {
public:
    vector<int> v;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        inorder(root);

        int f = 0;
        int b = v.size() - 1;

        while(f < b) {
            int sum = v[f] + v[b];

            if(sum == k)
                return true;
            else if(sum < k)
                f++;
            else
                b--;
        }

        return false;
    }
};