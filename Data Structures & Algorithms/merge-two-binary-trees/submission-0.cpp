class Solution {
public:
    // Notice I just used the main mergeTrees function instead of a helper function. 
    // It takes two nodes and returns one, so it's perfect for recursion on its own!
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        // Fix 2: The individual base cases
        if (root1 == nullptr) {
            return root2; 
        }
        if (root2 == nullptr) {
            return root1;
        }
        
        // If we made it here, BOTH nodes exist. 
        // Let's add root2's value into root1.
        root1->val = root1->val + root2->val;
        
        // Fix 3: Connect the recursive calls to root1's children
        root1->left = mergeTrees( root1->left ,root2->left );
        root1->right = mergeTrees( root1->right ,root2->right );
        
        // Return the newly merged root1
        return root1;
    }
};