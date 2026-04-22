class Twitter {
    int timeStamp = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;         // Fix 1: pair<int, int>
    unordered_map<int, unordered_set<int>> following;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> pq;
        
        // Fix 2: Added { ... } to the lambda body
        auto seed = [&](int uid) {
            if (tweets.count(uid) && !tweets[uid].empty()) {
                int idx = tweets[uid].size() - 1;
                auto [t, tid] = tweets[uid][idx];
                pq.push({t, tid, uid, idx - 1});
            }
        };
        
        seed(userId);
        // Fix 3: Changed ; to : in the for loop
        for (int followee : following[userId]) seed(followee);
        
        vector<int> feed;
        // Fix 4: Changed feed.size to feed.size()
        while (!pq.empty() && feed.size() < 10) {
            auto [t, tid, uid, nextIdx] = pq.top();
            pq.pop();
            feed.push_back(tid);
            
            if (nextIdx >= 0) {
                auto [nt, ntid] = tweets[uid][nextIdx];
                pq.push({nt, ntid, uid, nextIdx - 1});
            }
        }
        return feed;
    } // Fix 5: Moved the closing brace here so getNewsFeed includes everything
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) 
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};