// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int start = 0;
//        int bal = 0;
//        int i = 0;
//        int size = gas.size();
//        while(i < size){
//         if(gas[i]- cost[i] >= 0){
//             start = i;
//             int j = i;
//             bal = gas[i] - cost[i] + bal;
//             while(bal >= 0){
//                 j = (j+1) % size;
//                 if(j == start){
//                     return start;
//                 }
//                 bal = gas[j] - cost[j] + bal;
//             }
//             bal = 0;
//             if(j< i) return -1; // full circle checked !  mistake !
//             i = j+1;
//         }
//         else{
//         i++;    // mistake else nhi lagaya 
//         }
//        }
//        return -1; 
//     }
// };

// #2. Optimised Solution using Queue ! Thought -> pop from Front and move ahead 

// #3. Fully Optimised Using deficit and balance
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int balance = 0;
        int deficit = 0;
        int i =0;
        int start = 0;
        while(i< n){
           balance += gas[i]-cost[i];
           if(balance < 0){
            deficit += balance;
            start = i + 1;
            balance = 0;
           }
           i++;
        }
        if( balance + deficit >= 0) return start;
        else return -1;
    }
};
