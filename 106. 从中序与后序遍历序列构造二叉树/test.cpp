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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0)
        {
            return nullptr;
        }
        stack<TreeNode*> stk;
        auto root = new TreeNode(postorder[postorder.size() - 1]);
        stk.push(root);
        int inorderindex = inorder.size() - 1;
        for (int i = int(postorder.size() - 2); i >= 0; i--)
        {
            int postorderval = postorder[i];
            auto node = stk.top();
            if (node->val != inorder[inorderindex])
            {
                node->right = new TreeNode(postorderval);
                stk.push(node->right);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderindex])
                {
                    node = stk.top();
                    stk.pop();
                    inorderindex--;
                }
                node->left = new TreeNode(postorderval);
                stk.push(node->left);
            }
        }
        return root;
    }
};