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


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size())
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderindex = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int preorderval = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderindex])
            {
                node->left = new TreeNode(preorderval);
                stk.push(node->left);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderindex])
                {
                    node = stk.top();
                    stk.pop();
                    ++inorderindex;
                }
                node->right = new TreeNode(preorderval);
                stk.push(node->right);
            }
        }
        return root;
    }
};