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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        queue<int> num;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            vv.push_back(v);
        }
        reverse(vv.begin(), vv.end());
        return vv;
    }
};