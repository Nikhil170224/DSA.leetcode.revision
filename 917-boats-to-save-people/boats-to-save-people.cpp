class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // first we sort the array people
        sort(people.begin(),people.end());
        int n = people.size();
        int i = 0;
        int j = n-1;
        int boats = 0;
        while(i<=j){
            int sumOfWt =(i==j)? people[i] : people[i] + people[j];
            if(sumOfWt <= limit){
                boats++;
                i++;
                j--;
            }
            else{
                if(people[j] <= limit){
                    boats++;
                }
                j--;
            }
        }
        return boats;
    }
};