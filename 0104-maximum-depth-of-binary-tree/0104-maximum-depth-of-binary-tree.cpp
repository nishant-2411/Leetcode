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

int fun(TreeNode* root)
{
if(!root)                return 0;
return    1+max(    fun(root->left),fun(root->right)    );
}



class Solution {
public:
    int maxDepth(TreeNode* root) {
        
return      fun(root);

    }
};