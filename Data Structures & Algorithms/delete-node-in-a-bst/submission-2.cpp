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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if (key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(!root->left){
                TreeNode* rightchild=root->right;
                delete root;
                return rightchild;
            }
            if(!root->right){
                TreeNode* leftchild=root->left;
                delete root;
                return leftchild;
            }
            TreeNode* sucessor=root->right;
            while(sucessor->left) sucessor=sucessor->left;
            root->val=sucessor->val;
            root->right=deleteNode(root->right,sucessor->val); 
        }
        return root;
    }
};