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
public:
    int sumNumbers(TreeNode* root) { return dfs(root, 0); }
    int dfs(TreeNode* root, int prevsum) {
        prevsum = prevsum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return prevsum;
        }
        int ret = 0;
        if (root->left) {
            ret += dfs(root->left, prevsum);
        }
        if (root->right) {
            ret += dfs(root->right, prevsum);
        }
        return ret;
    }
};