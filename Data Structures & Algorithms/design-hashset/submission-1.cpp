class MyHashSet {
private:
    static const int BUCKETS=1009;
    vector<list<int>> table;
    int hash(int key){
        return key%BUCKETS;
    }
    list<int> ::iterator find(int key){
        int idx=hash(key);

        auto& bucket=table[idx];
        return std:: find(bucket.begin(),bucket.end(),key);
    }
public:

    MyHashSet():table(BUCKETS) {
        
    }
    
    void add(int key) {
        if(find(key)==table[hash(key)].end()){
            table[hash(key)].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx=hash(key);
        auto it=find(key);
        if(it!=table[idx].end()){
            table[idx].erase(it);
        }
        
    }
    
    bool contains(int key) {
        return find(key)!=table[hash(key)].end();
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */