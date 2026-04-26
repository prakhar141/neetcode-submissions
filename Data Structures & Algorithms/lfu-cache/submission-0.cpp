class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int,int> KeytoVal;
    unordered_map<int,int> KeytoFreq;
    unordered_map<int,list<int>> FreqtoList;
    unordered_map<int,list<int> ::iterator> KeytoIter;
    void touch(int key){
        int f=KeytoFreq[key];
        FreqtoList[f].erase(KeytoIter[key]);
        if(FreqtoList[f].empty()){
            FreqtoList.erase(f);
            if(minFreq==f) minFreq=f+1;
        }
        KeytoFreq[key]=f+1;
        FreqtoList[f+1].push_back(key);
        KeytoIter[key]=prev(FreqtoList[f+1].end());
    }
public:
    LFUCache(int capacity):capacity(capacity),minFreq{0} {
        
    }
    
    int get(int key) {
        if(KeytoVal.find(key)==KeytoVal.end()) return -1;
        touch(key);
        return KeytoVal[key];
        
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(KeytoVal.find(key)!=KeytoVal.end()){
            KeytoVal[key]=value;
            touch(key);
            return;
        }
        if((int)KeytoVal.size()==capacity){
            int evict=FreqtoList[minFreq].front();
            FreqtoList[minFreq].pop_front();
            if(FreqtoList[minFreq].empty()) FreqtoList.erase(minFreq);
            KeytoVal.erase(evict);
            KeytoFreq.erase(evict);
            KeytoIter.erase(evict);
        }
        KeytoVal[key]=value;
        KeytoFreq[key]=1;
        FreqtoList[1].push_back(key);
        KeytoIter[key]=prev(FreqtoList[1].end());
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */