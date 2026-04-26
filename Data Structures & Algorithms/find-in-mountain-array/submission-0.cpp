/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int lo=0;
        int hi=n-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        int peak=lo;
        int l=0;
        int r=peak;
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=mountainArr.get(mid);
            if(val==target) return mid;
            else if(val<target) l=mid+1;
            else r=mid-1;
        }
        l=peak+1;
        r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=mountainArr.get(mid);
            if(val==target) return mid;
            else if (val>target) l=mid+1;
            else r=mid-1;
        }
        return -1;
        
    }
};