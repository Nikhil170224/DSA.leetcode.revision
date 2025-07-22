class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int start = 0;
       int bal = 0;
       int i = 0;
       int size = gas.size();
       while(i < size){
        if(gas[i]- cost[i] >= 0){
            start = i;
            int j = i;
            bal = gas[i] - cost[i] + bal;
            while(bal >= 0){
                j = (j+1) % size;
                if(j == start){
                    return start;
                }
                bal = gas[j] - cost[j] + bal;
            }
            bal = 0;
            if(j< i) return -1; // full circle checked !
            i = j+1;
        }
        else{
        i++;
        }
       }
       return -1; 
    }
};