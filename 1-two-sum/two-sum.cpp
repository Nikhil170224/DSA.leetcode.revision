class Solution {
public:
    unordered_map<int,int>mp;
    vector<int> twoSum(vector<int>& nums, int target) {
      for(int i = 0; i< nums.size(); i++){
       if(mp.find(target-nums[i])!=mp.end()){
        return {i,mp[target-nums[i]]};
       }
       else{
        mp[nums[i]]=i;
       }
      } 
      return {-1,-1}; 
    }
};