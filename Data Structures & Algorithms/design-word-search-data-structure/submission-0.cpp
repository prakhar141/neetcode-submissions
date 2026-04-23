class WordDictionary {
private:
    struct Node{
        Node* children[26]={nullptr};
        bool isEnd=false;
    };
    Node* root;
    bool dfs(const string&word,int i,Node* node){
        if(!node) return false;
        if(i==word.size()) return node->isEnd;
        char c=word[i];
        if(c=='.'){
            for (int k=0;k<26;k++){
                if(node->children[k] && dfs(word,i+1,node->children[k])){
                    return true;
                }
                
            }
            return false;
        }
        else{
            return dfs(word,i+1,node->children[c-'a']);
        }
    }
public:
    WordDictionary() {
        root=new Node();
        
    }
    
    void addWord(string word) {
        Node* curr=root;
        for(char c:word){
            int idx=c-'a';
            if(!curr->children[idx]) curr->children[idx]=new Node();
            curr=curr->children[idx];
        }
        curr->isEnd=true;
        
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};
