class Solution {
public:
    vector<TreeNode*> nodes;
    vector<int> values;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);
        nodes.push_back(root);
        values.push_back(root->val);
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        sort(values.begin(), values.end());

        for(int i = 0; i < nodes.size(); i++) {
            nodes[i]->val = values[i];
        }
    }
};