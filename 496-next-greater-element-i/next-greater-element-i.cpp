// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>ans;
//         for(int i = 0; i< nums1.size(); i++){
//             for(int j = 0; j < nums2.size(); j++){
//                 if(nums1[i] == nums2[j]){
//                     int k = j;
//                     while(k < nums2.size()){
//                         if(nums2[k] > nums2[j]){
//                             ans.push_back(nums2[k]);
//                             break;
//                         }
//                         else{
//                             k++;
//                         }
//                     }
//                     if(k == nums2.size())
//                     ans.push_back(-1);
//                 }
//             }
//         }
//         return ans;
//     }
// };

//Optimisation-1 : Prestoring the index j for every value of nums1[i] in an Unordered_map

// class Solution {
// public:
//     unordered_map<int,int>indexOf;
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int>ans;
//         for(int j =0; j< nums2.size(); j++){
//             indexOf[nums2[j]] = j;
//         }
//         for(int i = 0; i< nums1.size(); i++){
//                 int k = indexOf[nums1[i]];
//                 while(k < nums2.size()){
//                     if(nums2[k] > nums1[i]){
//                         ans.push_back(nums2[k]);
//                         break;
//                     }
//                     else{
//                         k++;
//                     }
//                 }
//                 if(k == nums2.size())
//                 ans.push_back(-1);
//         }
//         return ans;
//     }
// };

//#Optimisation-2 : Using Stack Data Structure of finding the Next Greater Element
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        unordered_map<int,int>ansIdx;
        for(int i = 0; i< nums1.size(); i++){
            ansIdx[nums1[i]]= i;
        }

        stack<int>st; st.push(-1);
        for(int j = nums2.size()-1; j >= 0; j--){
                if(st.top()== -1){
               if(ansIdx.find(nums2[j]) != ansIdx.end()){ 
                ans[ansIdx[nums2[j]]]=st.top();}
                st.push(nums2[j]);
            }
            else{
                // elements are present in the stack
                if(st.top() > nums2[j]){
                   if(ansIdx.find(nums2[j]) != ansIdx.end()){ 
                    ans[ansIdx[nums2[j]]]=st.top();}
                    st.push(nums2[j]);
                }
                else{
                    while( st.top() != -1 && !(st.top() > nums2[j]) ){
                        st.pop();
                    }
                    if(ansIdx.find(nums2[j]) != ansIdx.end()){ 
                        ans[ansIdx[nums2[j]]]=st.top();}
                        st.push(nums2[j]);
                }
            }
        }
        return ans;
    }
};