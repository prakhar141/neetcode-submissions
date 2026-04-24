class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Fix 1: Corrected spelling to unordered_set, and capitalized wordList
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        // Fix 2: Actually declare the visited set
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                // Fix 3: Check must be INSIDE the for-i loop (word only lives here)
                // Fix 4: Added missing semicolon
                if (word == endWord) return level;
                
                // Fix 5: Neighbor generation must also be INSIDE the for-i loop
                //        (we must mutate every word we pop at this level)
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        word[j] = c;
                        
                        // Fix 6: Added ! (NOT) before visited.count(word)
                        //        We want UNVISITED words only
                        if (dict.count(word) && !visited.count(word)) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                    word[j] = original;
                }
            }
            
            // Fix 7: level++ must be INSIDE the while loop
            //        (one increment per BFS layer)
            level++;
        }
        
        return 0;
    }
};