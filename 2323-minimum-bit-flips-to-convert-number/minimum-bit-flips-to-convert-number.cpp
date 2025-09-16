class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        for(int i =0; i< 32; i++){
            bool bitStart = start & (1<<i);
            bool bitGoal = goal & (1<<i);
            if(bitStart ^ bitGoal) count++;
        }
        return count;
    }
};