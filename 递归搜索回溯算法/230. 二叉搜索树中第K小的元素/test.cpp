#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int count, ret;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        count--;
        if (count == 0) {
            ret = root->val;
        }
        dfs(root->right);
    }
};