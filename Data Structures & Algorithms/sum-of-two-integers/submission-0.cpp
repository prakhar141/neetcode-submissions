class Solution {
public:
    int getSum(int a, int b) {
        unsigned ua=a;
        unsigned ub=b;
        while(ub!=0){
            unsigned int sumWithoutcarry=ua^ub;
            unsigned int carry=(ua&ub) <<1;
            ua=sumWithoutcarry;
            ub=carry;
        }
        return (int)ua;

    }
};
