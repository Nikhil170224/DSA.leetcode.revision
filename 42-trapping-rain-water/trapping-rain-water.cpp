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

// // #2 Approach T.C = O(n2) || S.C = O(1)
// class Solution {
// public:
//     void findRightMaxHeight(vector<int>& height, int& maxRightHeight, int& maxRightIdx){
//         int i = maxRightIdx+1;
//         for(i ; i< height.size(); i++){
//             if(height[i] >= maxRightHeight){
//                 maxRightHeight = height[i];
//                 maxRightIdx = i;
//             }
//         }
//         return;
//     }
//     int trap(vector<int>& height) {
//         int totalWaterTrapped = 0;
//         int maxRightHeight = 0, maxRightIdx = 0, maxLeftHeight = 0;
//         findRightMaxHeight(height,maxRightHeight,maxRightIdx);
//         for(int i = 0; i< height.size(); i++){
//             // At every index i 
//             // step 1 : find the left max heighted wall
//             // step 2 : find the right max heighted wall
//             // step 3 : sum = min(leftMaxheight,rightMaxheight) - currHeight;
//             int currHeight = height[i];
//             int waterTrapped = min(maxLeftHeight, maxRightHeight) - currHeight;
//             if(waterTrapped > 0){
//                 totalWaterTrapped += waterTrapped;
//             }
//             maxLeftHeight = max(maxLeftHeight,height[i]);
//             // after i crosses the rightMaxHeight index we have to again call the function
//             if(i == maxRightIdx-1){
//                 maxRightHeight = 0;
//                 findRightMaxHeight(height,maxRightHeight,maxRightIdx);
//             }
//         }
//         return totalWaterTrapped;
//     }
// };

// #3 Approach - we gona use an array to store the maxRightHeight for all the indices and after that What we gona do, we can ensure faster Lookups for maxRightHeight --> T.C = O(n) || S.C = O(n)
class Solution {
public:
 void findRightMaxHeight(vector<int>& height, vector<int>& maxRightHeight){
    int n = height.size();
    int maxHeight = 0;
    for(int i = n - 1; i >= 0; i--){
        maxRightHeight[i] = maxHeight;
        maxHeight = max(maxHeight, height[i]);
    }
}
    int trap(vector<int>& height) {
        vector<int>maxRightHeight(height.size(),0);
        findRightMaxHeight(height,maxRightHeight);
        int totalWaterTrapped = 0;
        int maxLeftHeight = 0;
        for(int i = 0; i< height.size(); i++){
            int currHeight = height[i];
            int waterTrapped = min(maxLeftHeight, maxRightHeight[i]) - currHeight;
            if(waterTrapped > 0){
                totalWaterTrapped += waterTrapped;
            }
            maxLeftHeight = max(maxLeftHeight,height[i]);
        }
        return totalWaterTrapped;
    }
};