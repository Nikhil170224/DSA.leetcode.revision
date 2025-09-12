class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        int num = n;
        int ones = 0;
        while(num != 0){
            if(num & 1) ones++;
            num = num >> 1;
        }
        return (ones == 1) ? true : false;
    }
};