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
    vector<string> v;
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        dfs(root, path);
        return v;
    }
    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {

            v.push_back(path);
            return;
        }
        path += "->";
        if (root->left)
        {
            dfs(root->left, path);
        }
        if (root->right)
        {
            dfs(root->right, path);
        }
    }
};