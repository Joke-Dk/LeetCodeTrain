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
    vector<int> ret;
    void travel(TreeNode * root)
    {
        if(!root) return;
        travel(root->left);
        ret.push_back(root->val);
        travel(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        travel(root);
        return ret;
    }
};