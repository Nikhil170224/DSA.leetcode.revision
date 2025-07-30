// #1. Brute Force solution : T.C = O(N*N) & S.C = O(1);
// class Solution {
// public:
//     long long subArrayRanges(vector<int>& nums) {
//         int start = 0;
//         int ans = 0;
//         int n = nums.size();
//         while(start < n){
//             int end = start+1;
//             int smallest = nums[start];
//             int largest = nums[start];
//             while(end < n){
//                 smallest = min(smallest, nums[end]);
//                 largest = max(largest, nums[end]);
//                 int range = largest - smallest;
//                 ans += range;
//                 end++;
//             }
//             start++;
//         }
//         return ans;
//     }
// };

// #2.Optimised : T.C = O(N) & S.C = O(N) {precompute the largest and smallest element and store in an array of same size as that of nums given in the problem}
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        total += getSum(nums, true);  // Contribution as max
        total -= getSum(nums, false); // Contribution as min

        return total;
    }

private:
    long long getSum(vector<int>& nums, bool isMax) {
        int n = nums.size();
        stack<int> st;
        long long result = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && 
                   (i == n || (isMax ? nums[st.top()] < nums[i] : nums[st.top()] > nums[i]))) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long count = (mid - left) * (right - mid);
                result += count * nums[mid];
            }
            st.push(i);
        }

        return result;
    }
};

