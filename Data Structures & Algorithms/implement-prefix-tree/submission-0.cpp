class PrefixTree {
private:
struct Node{
    Node* children[26]={nullptr};
    bool isEnd=false;
};
Node* root;
public:
    PrefixTree() {
        root=new Node();
        
    }
    
    void insert(string word) {
        Node* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(!curr->children[idx]){
                curr->children[idx]=new Node;
            }
            curr=curr->children[idx];

        }
        curr->isEnd=true;
        
    }
    
    bool search(string word) {
        Node* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(!curr->children[idx]) return false;
            curr=curr->children[idx];
        }
        return curr->isEnd;
        
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(char c:prefix){
            int idx=c-'a';
            if(!curr->children[idx]) return false;
            curr=curr->children[idx];
        }
        return true;
        
    }
};
