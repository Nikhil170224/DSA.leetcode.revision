// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int>st;
//         st.push(-1);
//         int ans = INT_MIN;
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == '('){
//                 st.push(i);
//             }
//             else{
//                 st.pop();
//                 if(!st.empty()){
//                    int len = i- st.top(); 
//                    ans = max(ans,len);
//                 }
//                 else{
//                     st.push(i);
//                 }
//             }
//         }
//         if(ans <= 0){
//             return 0;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxlen = 0;
        for(int i = 0; i< s.size(); i++){
            char currEle = s[i];
            if(currEle == ')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    maxlen = max(maxlen, len);
                }
            }
            else{
                st.push(i);
            }
        }
        return maxlen;
    }
};