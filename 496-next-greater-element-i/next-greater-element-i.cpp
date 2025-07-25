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

class Solution {
public:
    unordered_map<int,int>indexOf;
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int j =0; j< nums2.size(); j++){
            indexOf[nums2[j]] = j;
        }
        for(int i = 0; i< nums1.size(); i++){
                int k = indexOf[nums1[i]];
                while(k < nums2.size()){
                    if(nums2[k] > nums1[i]){
                        ans.push_back(nums2[k]);
                        break;
                    }
                    else{
                        k++;
                    }
                }
                if(k == nums2.size())
                ans.push_back(-1);
        }
        return ans;
    }
};