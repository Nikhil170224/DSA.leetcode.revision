class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // pushing the answer of the first k elements of the first window 
        ans.push_back(nums[dq.front()]);

        // i = k and i > k elements 
        for(int i = k; i < nums.size(); i++){
            // removing the out of window elements from the queue if any 
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }

            // analysing the next k elements 
           while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        
        // pushing the answer of the first k elements of the first window 
        ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};