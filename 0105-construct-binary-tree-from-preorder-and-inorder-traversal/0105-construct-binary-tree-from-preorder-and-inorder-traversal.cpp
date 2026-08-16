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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    int preIndex = 0;

    function<TreeNode*(int, int)> solve = [&](int inStart, int inEnd) -> TreeNode* {
        
      
        if (inStart > inEnd)
            return nullptr;

        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inStart;
        while (inorder[rootIndex] != rootValue)
            rootIndex++;

        root->left = solve(inStart, rootIndex - 1);

        root->right = solve(rootIndex + 1, inEnd);

        return root;
    };

    return solve(0, inorder.size() - 1);
}
};