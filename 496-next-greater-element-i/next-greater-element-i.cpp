class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i = 0; i< nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int k = j;
                    while(k < nums2.size()){
                        if(nums2[k] > nums2[j]){
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
            }
        }
        return ans;
    }
};