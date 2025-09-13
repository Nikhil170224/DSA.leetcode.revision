class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        // Traverse all 32 bits
        for (int i = 0; i < 32; i++) {
            int countSetBits = 0;
            for (int num : nums) {
                if (num & (1 << i)) countSetBits++;
            }
            // If not divisible by 3, this bit belongs to the single number
            if (countSetBits % 3 != 0) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};
