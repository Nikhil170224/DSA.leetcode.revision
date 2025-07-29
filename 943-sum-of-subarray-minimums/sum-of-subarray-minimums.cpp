// #1. brute force approach : T.C = O(N*N) S.C = O(1);
// class Solution {
// public:
//     long long M = pow(10,9) + 7;
//     int sumSubarrayMins(vector<int>& arr) {
//         // sort(arr.begin(), arr.end()); Wrong : We assumed the order of subarray doesnot needed but After sometime I realised that the order in which arr is given in Problem is mandatory.
//         int n = arr.size();
//         int ans = 0;
//         int start = 0;
//         while(start < n){
//             int end = start;
//             int mini = arr[start];
//             while(end < n){
//                 mini = min(mini, arr[end]);
//                 ans += mini;
//                 end++;
//             }
//             start++;
//         }
//         return ans % M;
//     }
// };

// #2. Optimised : we will precompute the next smaller elemets and prev smaller elements and using that we lookup each index of the arr and find the no. of times every minimum element is involved in number of subarrays ==> T.C = O(N) & S.C = O(N).

class Solution {
public:
    long long M = pow(10,9) + 7;
    void NextSmallerEle(vector<int>&nextSmallerEle,vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSmallerEle[i] = st.top();
            }
            st.push(i);
        }
    }

    void PrevSmallerEle(vector<int>&prevSmallerEle,vector<int>& arr){
        int n = arr.size();
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmallerEle[i] = st.top();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nextSmallerEle(n,n);
        vector<int>prevSmallerEle(n,-1);
        NextSmallerEle(nextSmallerEle,arr);
        PrevSmallerEle(prevSmallerEle,arr);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long left = i - prevSmallerEle[i];
            long long right = nextSmallerEle[i] -i;
            ans = (ans+ (((left * right * 1LL)% M) * arr[i]) % M) % M;
        }
        return ans;
    }
};