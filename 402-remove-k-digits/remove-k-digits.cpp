// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<int>st;
//         for(int i = 0; i< num.size(); i++){
//             if(k != 0 && !st.empty() && st.top() > num[i] ){
//                 st.pop();
//                 k--;
//             }
//             st.push(num[i]);
//         }
//         // pushing all the digits left in the stack into the output string smallerInt
//         int size = st.size();
//         string smallerInt(size,0);
//         int i = size-1;
//         while(!st.empty()){
//             smallerInt[i] = st.top();
//             st.pop();
//             i--;
//         }
//         return smallerInt;
//     }
// };

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // Remove remaining digits if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the number from stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int nonZeroIdx = 0;
        while (nonZeroIdx < result.size() && result[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }

        result = result.substr(nonZeroIdx);

        return result.empty() ? "0" : result;
    }
};
