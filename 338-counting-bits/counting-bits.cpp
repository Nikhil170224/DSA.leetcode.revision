class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i =0; i<=n; i++){
        int count = 0;
        //count no. of 1s in i
        int decimalNo = i;
        while(decimalNo > 0){
            if(decimalNo & 1){
              count++;
            } 
            decimalNo= decimalNo>>1;

        }
        ans.push_back(count);
      }
      return ans;
    }
};