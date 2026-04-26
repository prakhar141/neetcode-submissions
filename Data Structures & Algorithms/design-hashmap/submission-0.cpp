class MyHashMap {
private:
    static const int SIZE=769;
    vector<list<pair<int,int>>> buckets;
    int hash(int key){
        return key%SIZE;
    }
    list<pair<int,int>> :: iterator find(int key){
        int idx=hash(key);
        auto& bucket=buckets[idx];
        for(auto it=bucket.begin();it!=bucket.end();it++){
            if(it->first == key) return it;
        }
        return bucket.end();
    }
public:
    MyHashMap() {
        buckets.resize(SIZE);
        
    }
    
    void put(int key, int value) {
        int idx=hash(key);
        auto it=find(key);
        if(it!=buckets[idx].end()){
            it->second=value;
        }
        else{
            buckets[idx].push_back({key,value});
        }
        
    }
    
    int get(int key) {
        int idx=hash(key);
        auto it=find(key);
        return(it!=buckets[idx].end()) ? it->second:-1;
        
    }
    
    void remove(int key) {
        int idx=hash(key);
        auto it=find(key);
        if(it!=buckets[idx].end()){
            buckets[idx].erase(it);
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */