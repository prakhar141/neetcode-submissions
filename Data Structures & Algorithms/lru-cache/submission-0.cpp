class LRUCache {
private:
    struct Node{
        int key,val;
        Node *prev,*next;
        Node(int k ,int v):key(k),val(v),prev(nullptr),next(nullptr) {}

    };
    int capacity;
    unordered_map<int,Node*> cache;
    Node *head,*tail;
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void addToFront(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void moveToFront(Node* node){
        removeNode(node);
        addToFront(node);
    }


public:
    LRUCache(int capacity):capacity(capacity) {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;

        
    }
    
    int get(int key) {
        if (cache.find(key)==cache.end()){
            return -1;
        }
        Node* node=cache[key];
        moveToFront(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node=cache[key];
            node->val=value;
            moveToFront(node);
            return;
        }
        if((int)cache.size()==capacity){
            Node* lru=tail->prev;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
        Node* node=new Node(key,value);
        cache[key]=node;
        addToFront(node);
        
    }
};
