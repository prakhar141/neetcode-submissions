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
    bool validate(TreeNode* node,long minval,long maxval){
        if(node==nullptr) return true;
        if(node->val<=minval || node->val>=maxval) return false;
        return validate(node->left,minval,node->val) && validate(node->right,node->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
         return validate(root,LONG_MIN,LONG_MAX);
        
    }
};
