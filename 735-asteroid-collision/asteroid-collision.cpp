// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int>st;
//         int n = asteroids.size();
//         int i = 0;
//         while(i< n){
//             if(!st.empty() && asteroids[i] < 0){
//                 while(!st.empty() && st.top() < abs(asteroids[i])){
//                     st.pop();
//                 }
//                 if(!st.empty() && st.top() > abs(asteroids[i])){
//                     i++;
//                 }
//                 if(!st.empty() && st.top() == abs(asteroids[i])){
//                     st.pop();
//                     i++;
//                 }
//             }
//             else{
//                st.push(asteroids[i]);
//                i++; 
//             }
//         }
//         int size = st.size();
//         vector<int>stateAfterCollisions(size);
//         for(int i = size-1; i>=0; i--){
//             stateAfterCollisions[i]= st.top();
//             st.pop();
//         }
//         return stateAfterCollisions;
//     }
// };
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            bool destroyed = false;
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (st.top() < -a) {
                    st.pop();
                    continue;
                } else if (st.top() == -a) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
