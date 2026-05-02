class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto C2=[](long long x)->long long{
            if(x<2) return 0;
            return x*(x-1)/2;
        };
        long long N=n;
        long long L=limit;
        return C2(N+2)-3*C2(N-L+1)+3*C2(N-2*L)-C2(N-3*L-1);
    }
};