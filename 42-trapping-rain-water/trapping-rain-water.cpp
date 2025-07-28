// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int totalSum = 0;
//         int sumOfHeights = accumulate(height.begin(),height.end(),0);
//         while(sumOfHeights != 0){
//             int i = 0;
//             int sum = 0; 
//             while(height[i] == 0){
//                 i++;
//             }
//             while(i< height.size()){
//                 // first non-zero number in the height array
//                 if(height[i] != 0){
//                     // append sum to totalSum
//                     totalSum += sum;
//                     sum = 0;
//                     height[i]--;
//                     sumOfHeights--;
//                     i++;
//                 }
//                 else{
//                     sum++;
//                     i++;
//                 }

//             }
//         }
//         return totalSum;
//     }
// };

// #2 Approach
class Solution {
public:
    void findRightMaxHeight(vector<int>& height, int& maxRightHeight, int& maxRightIdx){
        int i = maxRightIdx+1;
        for(i ; i< height.size(); i++){
            if(height[i] >= maxRightHeight){
                maxRightHeight = height[i];
                maxRightIdx = i;
            }
        }
        return;
    }
    int trap(vector<int>& height) {
        int totalWaterTrapped = 0;
        int maxRightHeight = 0, maxRightIdx = 0, maxLeftHeight = 0;
        findRightMaxHeight(height,maxRightHeight,maxRightIdx);
        for(int i = 0; i< height.size(); i++){
            // At every index i 
            // step 1 : find the left max heighted wall
            // step 2 : find the right max heighted wall
            // step 3 : sum = min(leftMaxheight,rightMaxheight) - currHeight;
            int currHeight = height[i];
            int waterTrapped = min(maxLeftHeight, maxRightHeight) - currHeight;
            if(waterTrapped > 0){
                totalWaterTrapped += waterTrapped;
            }
            maxLeftHeight = max(maxLeftHeight,height[i]);
            // after i crosses the rightMaxHeight index we have to again call the function
            if(i == maxRightIdx-1){
                maxRightHeight = 0;
                findRightMaxHeight(height,maxRightHeight,maxRightIdx);
            }
        }
        return totalWaterTrapped;
    }
};