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

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int le = maxDepth(root->left);
        int ri = maxDepth(root->right);
        if(abs(le-ri)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);;
    }
};