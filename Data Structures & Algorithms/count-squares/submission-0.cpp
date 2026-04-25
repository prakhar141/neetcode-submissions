class CountSquares {
private:
    map<pair<int,int>,int> freq;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0],point[1]}]++;
        
    }
    
    int count(vector<int> point) {
        int qx=point[0];
        int qy=point[1];
        int result=0;
        for(auto&[pt,cnt]:freq){
            int x=pt.first;
            int y=pt.second;
            if(abs(x-qx)!=abs(y-qy)||x==qx||y==qy){
                continue;
            }
            auto it1=freq.find({qx,y});
            auto it2=freq.find({x,qy});
            if(it1!=freq.end() && it2!=freq.end()){
                result+=cnt*it1->second*it2->second;
            }
        }
        return result;
        
    }
};
