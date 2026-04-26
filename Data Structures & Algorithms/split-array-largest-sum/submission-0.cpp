class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int pieces = 1;
        long long currentSum = 0;
        
        for (int num : nums) {
            // If adding this number exceeds maxSum, start a new piece
            if (currentSum + num > maxSum) {
                pieces++;
                currentSum = num; // Start the new piece with the current number
                
                // If we need more pieces than k, this maxSum is too small
                if (pieces > k) return false; 
            } 
            // Otherwise, just add it to the current piece
            else {
                currentSum += num;
            }
        }
        
        // If we finished the loop, it means we split it into <= k pieces
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;
        for (int num : nums) {
            lo = max(lo, (long long)num); // The minimum possible max sum is the largest single element
            hi += num;                    // The maximum possible max sum is the sum of all elements
        }
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2; // Note: (hi - lo), not (lo - hi)
            
            if (canSplit(nums, k, mid)) {
                hi = mid; // It's possible, try for a smaller max sum
            } else {
                lo = mid + 1; // Not possible, need a larger max sum
            }
        }
        
        return (int)lo;
    }
};