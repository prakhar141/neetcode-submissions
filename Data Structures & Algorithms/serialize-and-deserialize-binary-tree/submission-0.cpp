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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root,result);
        return result;        
    }
    void serializeHelper(TreeNode* node, string& out){
        if(!node) {
            out+="N,";
            return;
        }
        out+=to_string(node->val) + ",";
        serializeHelper(node->left,out);
        serializeHelper(node->right,out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue <string> tokens;
        string token;
        for(char c:data){
            if(c==','){
                tokens.push(token);
                token.clear();
            }
            else{
                token+=c;
            }
        }
        return deserializeHelper(tokens);
        
    }
    TreeNode* deserializeHelper(queue <string>& tokens){
        string val=tokens.front();
        tokens.pop();
        if (val=="N"){
            return nullptr;
        }
        TreeNode* node =new TreeNode(stoi(val));
        node->left=deserializeHelper(tokens);
        node->right=deserializeHelper(tokens);
        return node;
    }
};
