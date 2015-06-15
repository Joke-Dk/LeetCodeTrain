/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recusive( TreeNode* root)
    {
        if(!root) return;
        swap( root->left, root->right);
        recusive(root->left);
        recusive(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        recusive(root);
        return root;
    }
};
