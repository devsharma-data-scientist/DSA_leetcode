class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val)
            return root;

        if(val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }

    TreeNode* findParent(TreeNode* root, int val) {
        if(root == NULL || root->val == val)
            return NULL;

        if(val < root->val) {
            if(root->left && root->left->val == val)
                return root;

            return findParent(root->left, val);
        }
        else {
            if(root->right && root->right->val == val)
                return root;

            return findParent(root->right, val);
        }
    }

    TreeNode* findMax(TreeNode* root) {
        if(root == NULL)
            return NULL;

        if(root->right == NULL)
            return root;

        return findMax(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;

        if(key < root->val)
            root->left = deleteNode(root->left, key);

        else if(key > root->val)
            root->right = deleteNode(root->right, key);

        else {
            if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            TreeNode* predecessor = findMax(root->left);
            root->val = predecessor->val;
            root->left = deleteNode(root->left, predecessor->val);
        }

        return root;
    }
};