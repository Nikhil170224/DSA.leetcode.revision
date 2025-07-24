class Solution {
public:
    bool checkPossible(vector<int>& nums, int k,int mid){
        int c  = 1;
        int sum = 0;
        for(int i =0; i < nums.size(); i++){
            if(nums[i] > mid) return 0;
            if(sum + nums[i] > mid){
                sum = nums[i];
                c++;
                if(c>k){
                return 0;
            }
            }
            else{
                sum += nums[i];
            }
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = 0;
        int e = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while(s <= e){
            int mid = s + (e-s)/2;
            bool possible = checkPossible(nums,k,mid);
            if(possible){
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid +1;
            }

        }
        return ans;
    }
};