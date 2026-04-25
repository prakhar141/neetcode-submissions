/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n=intervals.size();
        vector<int> starts(n),ends(n);
        for(int i=0;i<n;i++){
            starts[i]=intervals[i].start;
            ends[i]=intervals[i].end;
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        int rooms=0;
        int e=0;
        for(int s=0;s<n;s++){
            if(starts[s]<ends[e]){
                rooms++;
            }
            else{
                e++;
            }
        }
        return rooms;
    }
};
