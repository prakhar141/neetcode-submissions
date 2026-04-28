class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        int maxLen=1;
        int len=1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                len=1;
            }
            else if(i==1 ||(arr[i]> arr[i-1] && arr[i-1] < arr[i-2])||(arr[i]<arr[i-1] && arr[i-1]>arr[i-2])) len++;
            else len=2;
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};