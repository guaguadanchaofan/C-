#define  _CRT_SECURE_NO_WARNINGS
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
    string tree2str(TreeNode* root) {
        if (root == nullptr)
        {
            return "";
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return to_string(root->val);
        }
        if (root->right == nullptr)
        {
            return to_string(root->val) + '(' + tree2str(root->left) + ')';
        }
        return to_string(root->val) + '(' + tree2str(root->left) + ')' + '(' + tree2str(root->right) + ')';
    }
};