class Solution {
public:

    void solve(vector<string>&ans,string output,int n,int open,int close){
        //Base Case
        if(open <= 0 && close <= 0){
            ans.push_back(output);
            return;
        }

        //ek case solve kardo
        // include open
        if(open > 0){
            // output.push_back('(');
            solve(ans,output+'(', n,open-1, close);
            //Backtracking
            // output.pop_back();
        }
        // include close
        if(close > open){
            // output.push_back(')');
            solve(ans,output+')', n,open, close-1);
           //Backtracking
            // output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output = "";
        int open =n;
        int close = n;
        solve(ans,output,n,open,close);
        return ans;
    }
};