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
#include<climits>
class Solution {
public:
    int maxSum=0;
    int dfs(TreeNode* node){
        if(!node) return 0;
        int leftGain=max(dfs(node->left),0);
        int rightGain=max(dfs(node->right),0);
        int bentPath=node->val+leftGain+rightGain;
        maxSum=max(maxSum,bentPath);
        return node->val + max(leftGain,rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        dfs(root);
        return maxSum;

    }
};
