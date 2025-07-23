class Solution {
public:

int maxele(vector<int>& piles){
    int maxi = INT_MIN;
    for(int i = 0; i<piles.size(); i++){
        maxi = max(maxi,piles[i]);
    }
    return maxi;
}
bool checkpossi(vector<int>& piles, int h,int mid){
    // int c = 1, j =0;
    // while(j<piles.size()){
    //     int bananas = piles[j];
    //     if(c>h){
    //         return 0;
    //     }
    //      while(bananas>=0){
    //         bananas-=mid;
    //         c++;
    //         if(bananas+mid==0){
    //             c--;
    //         }
    //     }
    //     j++;
    // }
    // return 1;

    // **Ceiling of Division Function**
    long hours = 0;
    for(int i =0; i<piles.size(); i++){
        hours += (piles[i] + mid -1)/mid;
    }
    return hours<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = maxele(piles);
        int mid = s + (e-s)/2;
        int ans= e;
        while(s<=e){
            int possibility = checkpossi(piles,h,mid);
            if(possibility){
                ans = mid;
                e =mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;

    }
};